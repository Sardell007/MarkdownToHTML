/**
 * @file log.h
 * @author Chilukamari Shiva Sai Krishna (mcs232499@cse.iitd.ac.in)
 * @brief Loggin helper to switch On-Off printf statements
 * @version 0.1
 * @date 2023-08-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief If DEBUG defined, Log prints are swicthed On, Else prints are off
 * 
 */
// #define DEBUG

#ifdef DEBUG
#define DEBUG_LOG(x) x
#else
#define DEBUG_LOG(x)
#endif