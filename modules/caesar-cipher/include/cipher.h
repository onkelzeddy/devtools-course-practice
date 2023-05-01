// Copyright 2023 Kolesov Maxim

#pragma once

#include <string>

/**
 * @defgroup caesar_cipher Caesar cipher
 * @{
 */

/**
 * @defgroup kernel Cipher kernel
 * @ingroup caesar_cipher
 * @{
 */

/**
 * @brief Contains cipher settings
 * @see #CaesarCipher
 * @author Maxim Kolesov
 */
struct Kernel {
  /**
   * @brief Contains all letters of the alphabet
   */
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

  /**
   * @brief Set how many letters should be skipped when encoding
   */
  uint32_t shift = 5;

  /**
   * @brief Sets whether to include unfamiliar letters
   */
  bool foreignChars = true;

  /**
   * @brief Kernel constructor
   * @param shift @see #shift
   * @param alphabet @see #alphabet
   * @param foreignChars @see #foreignChars
   */
  explicit Kernel(
      uint32_t shift = 5,
      const std::string &alphabet = "abcdefghijklmnopqrstuvwxyz",
      bool foreignChars = true);

  Kernel &operator=(const Kernel &k) = default;

  /**
   * Check if this kernel is equal to k
   * @param[in] k another kernel
   * @return kernel equals to k
   */
  bool operator==(const Kernel &k) const;
  /**
   * Check if this kernel is not equal to k
   * @param[in] k another kernel
   * @return kernel is not equal to k
   */
  bool operator!=(const Kernel &k) const;
} const defaultKernel;

//! @}

/**
 * @brief Class represent caesar cipher.
 * @link https://en.wikipedia.org/wiki/Caesar_cipher
 * @author Maxim Kolesov
 */
class CaesarCipher {
 public:
  /**
   * @brief Create Caesar cipher with specific kernel
   * @param[in] k by default is #defaultKernel
   * @see #Kernel
   */
  explicit CaesarCipher(const Kernel &k = defaultKernel);

  /**
   * @brief Default copy constructor
   */
  CaesarCipher(const CaesarCipher &c) = default;

  /**
   * @brief Default move constructor
   */
  CaesarCipher(CaesarCipher &&c) = default;

  /**
   * @brief Default destructor
   */
  ~CaesarCipher() = default;

  /**
   * @brief Copy assigment operator
   * @param[in] c CaesarCipher to copy
   * @return Reference to current object with new kernel
   */
  CaesarCipher &operator=(const CaesarCipher &c) = default;

  /**
   * @brief Move assigment operator
   * @param[in] c CaesarCipher to copy
   * @return Reference to current object with new kernel
   */
  CaesarCipher &operator=(CaesarCipher &&c) = default;

  /**
   * @brief Encode message with current kernel
   * @param[in] message
   * @return Encoded message
   */
  std::string encode(const std::string &message) const;

  /**
   * @brief Decode message with current kernel
   * @param[in] message encoded message
   * @return Decoded message
   */
  std::string decode(const std::string &message) const;

  /**
   * @return const reference of current cipher's kernel
   * @see #Kernel
   */
  const Kernel &getKernel() const;

  /**
   * Check if this cipher is equal to c
   * @param[in] c another CaesarCipher
   * @return cipher equals to c
   */
  bool operator==(const CaesarCipher &c) const;

  /**
 * Check if this cipher is not equal to c
 * @param[in] c another CaesarCipher
 * @return cipher is not equal to c
 */
  bool operator!=(const CaesarCipher &c) const;

 private:
  /**
   * @brief contains current cipher settings
   */
  Kernel m_kernel;
};

//! @}
