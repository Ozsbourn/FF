#include <cassert>

#ifndef FF_MACROS_HXX_
#define FF_MACROS_HXX_

namespace FF {
	#define __FF_IN  
	#define __FF_OUT 

	#ifdef __FF_DEBUG
		#define FF_ASSERT(CONDITION) 						assert(CONDITION)
		#define FF_ASSERT_MESSAGE(CONDITION, ERROR_MESSAGE) assert(CONDITION && ERROR_MESSAGE)

		#define FF_VERIFY(CONDITION)						assert(CONDITION)
	#else
		#define FF_ASSERT(CONDITION) 
		#define FF_ASSERT_MESSAGE(CONDITION, ERROR_MESSAGE) 

		#define FF_VERIFY(CONDITION)						(CONDITION)
	#endif
};

#endif // FF_MACROS_HXX_