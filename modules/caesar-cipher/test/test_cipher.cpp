// Copyright 2023 Kolesov Maxim

#include <gtest/gtest.h>
#include "include/cipher.h"

TEST(CaesarCipher, assert_no_throw_in_default_constructor) {
  ASSERT_NO_THROW(CaesarCipher cc);
}

TEST(CaesarCipher, create_cipher_with_specific_kernel) {
  Kernel kernel(7, "abc");

  CaesarCipher cipher(kernel);

  EXPECT_EQ(kernel, cipher.getKernel());
}

TEST(CaesarCipher, copy_cipher) {
  Kernel kernel(7, "abc");

  CaesarCipher origin = CaesarCipher(kernel);

  CaesarCipher copy = CaesarCipher(origin);

  EXPECT_EQ(origin, copy);
}

TEST(CaesarCipher, move_cipher) {
  Kernel kernel(2);
  CaesarCipher origin(kernel);

  CaesarCipher mv = std::move(origin);

  EXPECT_EQ(kernel, mv.getKernel());
}

TEST(CaesarCipher, kernel_equal) {
  Kernel k(6, "tes", false),
         e(6, "tes", false);

  EXPECT_EQ(k, e);
}

TEST(CaesarCipher, kernel_not_equal) {
  Kernel k(6, "tes"),
         e(6, "tes", false);

  EXPECT_NE(k, e);
}

TEST(CaesarCipher, assign) {
  Kernel k(42);
  CaesarCipher origin(k);

  CaesarCipher assigned = origin;

  EXPECT_EQ(assigned.getKernel(), k);
}

TEST(CaesarCipher, equal) {
  CaesarCipher c1, c2;

  EXPECT_EQ(c1, c2);
}

TEST(CaesarCipher, not_equal) {
  Kernel k(42);
  CaesarCipher c1, c2(k);

  EXPECT_NE(c1, c2);
}

TEST(CaesarCipher, remove_equal_characters_in_constructor) {
  Kernel k;
  k.alphabet = "test";

  CaesarCipher c(k);

  EXPECT_EQ(c.getKernel().alphabet, "tes");
}

TEST(CaesarCipher, get_kernel) {
  Kernel k(42);
  CaesarCipher c(k);

  const Kernel &get = c.getKernel();

  EXPECT_EQ(get, k);
}

TEST(CaesarCipher, encode) {
  CaesarCipher c;

  std::string result = c.encode("test");

  EXPECT_EQ(result, "yjxy");
}

TEST(CaesarCipher, encode_with_space) {
  CaesarCipher c;

  std::string result = c.encode("this is a test");

  EXPECT_EQ(result, "ymnx nx f yjxy");
}

TEST(CaesarCipher, encode_with_no_space) {
  Kernel k;
  k.foreignChars = false;
  CaesarCipher c(k);

  std::string result = c.encode("this is a test");

  EXPECT_EQ(result, "ymnxnxfyjxy");
}

TEST(CaesarCipher, decode) {
  CaesarCipher c;

  std::string result = c.decode("yjxy");

  EXPECT_EQ(result, "test");
}

TEST(CaesarCipher, decode_with_space) {
  CaesarCipher c;

  std::string result = c.decode("ymnx nx f yjxy");

  EXPECT_EQ(result, "this is a test");
}

TEST(CaesarCipher, decode_with_no_space) {
  Kernel k;
  k.foreignChars = false;
  CaesarCipher c(k);

  std::string result = c.decode("ymnx nx f yjxy");

  EXPECT_EQ(result, "thisisatest");
}
