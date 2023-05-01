// Copyright 2023 Kolesov Maxim

#include "include/cipher.h"

bool Kernel::operator==(const Kernel &k) const {
  return
    alphabet == k.alphabet &&
    shift == k.shift &&
    foreignChars == k.foreignChars;
}

bool Kernel::operator!=(const Kernel &k) const {
  return !(*this == k);
}
Kernel::Kernel(uint32_t shift, const std::string &alphabet, bool foreignChars)
  : alphabet(alphabet), shift(shift), foreignChars(foreignChars) {}

CaesarCipher::CaesarCipher(const Kernel &k) {
  std::string builder;

  for (const auto &c : k.alphabet) {
    if (builder.find(c) == std::string::npos) {
      builder.push_back(c);
    }
  }

  m_kernel.alphabet = builder;
  m_kernel.shift = k.shift;
  m_kernel.foreignChars = k.foreignChars;
}

const Kernel &CaesarCipher::getKernel() const {
  return m_kernel;
}
bool CaesarCipher::operator==(const CaesarCipher &c) const {
  return m_kernel == c.m_kernel;
}
bool CaesarCipher::operator!=(const CaesarCipher &c) const {
  return !(m_kernel == c.m_kernel);
}
std::string CaesarCipher::encode(const std::string &message) const {
  std::string builder;

  for (const auto &c : message) {
    const std::string::size_type index = m_kernel.alphabet.find(c);

    if (index == std::string::npos) {  // does not contain
      if (m_kernel.foreignChars) {
        builder.push_back(c);
      }

      continue;
    }

    builder.push_back(
        m_kernel.alphabet[(index + m_kernel.shift) % m_kernel.alphabet.size()]);
  }

  return builder;
}
std::string CaesarCipher::decode(const std::string &message) const {
  std::string builder;

  for (const auto &c : message) {
    const std::string::size_type index = m_kernel.alphabet.find(c);
    if (index == std::string::npos) {  // does not contain
      if (m_kernel.foreignChars) {
        builder.push_back(c);
      }

      continue;
    }

    const auto i = static_cast<int32_t>(index);
    const auto s = static_cast<int32_t>(m_kernel.shift);
    builder.push_back(
        m_kernel.alphabet[
            std::abs(i - s) % m_kernel.alphabet.size()
          ]);
  }

  return builder;
}
