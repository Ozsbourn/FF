#include <cassert>

#ifndef FF_MACROS_HXX_
#define FF_MACROS_HXX_

namespace FF {
    /**
     * @brief [Input parameter macro]
     * @details [A macro showing that the parameter of the function or method before which it is written is an input]
     */
    #define __FF_IN  
    /**
     * @brief [Output parameter macro]
     * @details [A macro showing that the parameter of the function or method before which it is written is an output]
     */
    #define __FF_OUT 

    /**
     * @brief [Debug macro]
     * @details [Debug macro define the ASSERTs and VERIFY macros that expanding to appropriate functions or condition]
     */
    #ifdef __FF_DEBUG
        /**
        * @brief [Assert macro]
        * @details [In debug expanding to assert without message]
        */
        #define FF_ASSERT(CONDITION)                        assert(CONDITION)
        /**
        * @brief [Assert with message macro]
        * @details [In debug expanding to assert with message]
        */
        #define FF_ASSERT_MESSAGE(CONDITION, ERROR_MESSAGE) assert(CONDITION && ERROR_MESSAGE)

        /**
        * @brief [Verify macro]
        * @details [In debug expanding to assert without message]
        */
        #define FF_VERIFY(CONDITION)                        assert(CONDITION)
    #else
        /**
        * @brief [Assert macro]
        * @details [In release expanding to assert without message]
        */
        #define FF_ASSERT(CONDITION) 
        /**
        * @brief [Assert with message macro]
        * @details [In release expanding to assert with message]
        */
        #define FF_ASSERT_MESSAGE(CONDITION, ERROR_MESSAGE) 

        /**
        * @brief [Verify macro]
        * @details [In release expanding to condition]
        */
        #define FF_VERIFY(CONDITION)                        (CONDITION)
    #endif
};

#endif // FF_MACROS_HXX_