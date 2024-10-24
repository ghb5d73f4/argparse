/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- file: argparse.h -*-
 -*- author: G.Henning -*-
 -*- copyright: GH / IPHC (2013) -*-
 -*- date:  Sept 26 2013 -*-
 -*- purpose: Parse arguments from command line -*-
**/

/* includes */
#include "argparse.h"

const int ParseFlag(const int argc,
		    const char* argv[],
		    const char* flag)
{
  /**
   * @brief Checks if the specified flag is present in the command-line arguments.
   *
   * This function searches for a specific flag (e.g., "-h" or "--help") within the arguments passed
   * to the program. It returns 1 if the flag is found, and 0 otherwise.
   *
   * @param argc Number of command-line arguments.
   * @param argv Array of argument strings.
   * @param flag The flag to search for (e.g., "-h", "--verbose").
   * @return int 1 if the flag is present, 0 otherwise.
   *
   * @note This function does an exact string match with the flag. Ensure that the flag string matches
   * the format of the argument (including dashes).
   */
  for (int n =0 ; n<argc; n++)
    if (strcmp(argv[n], flag)==0)
      return 1;
  return 0;
}

const int ParseInt(const int argc,
		   const char* argv[],
		   const char* arg,
		   const int orelse)
{
    /**
   * @brief Parses an integer argument from the command line.
   *
   * Searches for the given format string (e.g., "--num=%d") within the command-line arguments and
   * parses the integer value associated with it. If the argument is not found, it returns the
   * provided default value.
   *
   * @param argc Number of command-line arguments.
   * @param argv Array of argument strings.
   * @param arg Format string used to identify the integer argument (e.g., "--num=%d").
   * @param orelse The fallback value returned if the argument is not found.
   * @return int Parsed integer or the fallback value if not found.
   *
   * @note The function uses sscanf to parse the integer value. Ensure that the format string
   * matches the command-line argument.
   */
  int retval;
  for (int n =0 ; n<argc; n++)
    if (sscanf(argv[n], arg, &retval)==1)
      return (const int) retval;
  return orelse;
}

const float ParseFloat(const int argc,
		       const char* argv[],
		       const char* arg,
		       const float orelse)
{
    /**
   * @brief Parses a floating-point argument from the command line.
   *
   * Similar to ParseInt, this function searches for a float argument using a format string (e.g., "--ratio=%f")
   * and returns the parsed float value. If the argument is not found, it returns the specified fallback value.
   *
   * @param argc Number of command-line arguments.
   * @param argv Array of argument strings.
   * @param arg Format string used to identify the float argument (e.g., "--ratio=%f").
   * @param orelse Default value returned if the float argument is not found.
   * @return float Parsed float or the fallback value if not found.
   *
   * @note Like ParseInt, this function relies on sscanf to parse the argument. Ensure that the
   * format string is correctly formatted to identify the float argument.
   */
  float retval;
  for (int n =0 ; n<argc; n++)
    if (sscanf(argv[n], arg, &retval)==1)
      return (const float) retval;
  return orelse;
}

const char* ParseString(const int argc,
			const char* argv[],
			const char* arg,
			const char* orelse)
{
    /**
   * @brief Parses a string argument from the command line.
   *
   * This function looks for a string argument matching the provided format string (e.g., "--name=%s").
   * If found, the argument is copied into a static buffer and returned. If the argument is not found,
   * it returns the specified fallback string.
   *
   * @param argc Number of command-line arguments.
   * @param argv Array of argument strings.
   * @param arg Format string used to identify the string argument (e.g., "--name=%s").
   * @param orelse Default string returned if the argument is not found.
   * @return const char* The parsed string or the fallback value.
   *
   * @note The buffer used to hold the parsed string is static, so the returned pointer remains
   * valid even after the function returns.
   */
  char *retval;
  retval = (char*)malloc(1024*sizeof(char));
  if (retval==NULL)
    return orelse;
  for (int n =0 ; n<argc; n++)
    if (sscanf(argv[n], arg, retval)==1)
      return retval;
  return orelse;
}

const int CountArgs(const int argc,
		    const char* argv[])
{
/**
 * @brief Returns the number of non-flag, non-option arguments passed (i.e. not starting with `-`)
 *
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @return int The total number of arguments.
 */
  int retval = 0;
  for (int n = 1; n<argc; n++)
    {
      if (argv[n][0]!='-' && argv[n]!=NULL)
	{
	  retval++;
	}
    }
  return retval;
}


const char** GetArgs(const int argc,
		     const char* argv[],
		     const int ArgCount)
{
/**
 * @brief Retrieves all  non-flag, non-option arguments passed (i.e. not starting with `-`)
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @param ArgCount Number of arguments to retrieve (from `CountArgs()`).
 * @return const char** Array of argument strings.
 *
 */

  const char** arg_array = (const char**) malloc(ArgCount * sizeof(char*));

  if (arg_array==NULL)
    return NULL;

  int n_arg_array = 0;
  for (int n = 1; n < argc; n++)
    {
      if (argv[n][0]!='-' && argv[n]!=NULL)
	{
	  arg_array[n_arg_array++] = argv[n];
	}
    }

  return arg_array;
}

/** end of file **/