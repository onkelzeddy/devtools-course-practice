// Copyright 2023 Kolesov Maxim

#pragma once

#include <string>

//! @addtogroup complex-number
//! @{

/**
 * @brief Class for binary search
 */
class SearchApplication {
 public:
  SearchApplication() = default;

  SearchApplication(const SearchApplication &sa) = delete;
  SearchApplication(SearchApplication &&sa) = delete;

  /**
   * @brief Functor override
   * @param[in] argc Nuber of comand line arguments
   * @param[in] argv Command line arguments
   * @return Output expression
   */
  std::string operator()(int argc, const char **argv);

 private:
  /**
   * @brief Set m_message field to help message.
   * @param[in] appName Name of application binary
   */
  void help(const char *appName);

  /**
   * @brief Validate console arguments
   * @param[in] argc Nuber of comand line arguments
   * @param[in] argv Command line arguments
   * @return
   */
  bool validateArguments(int argc, const char **argv);

  std::string m_message;
};

//! @}
