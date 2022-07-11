#ifndef FF_COMMONMATH_HXX_
#define FF_COMMONMATH_HXX_

namespace FF {
	// Constants
	static constexpr float  fPI      = 3.14'15'92f;
	static constexpr double dPI      = 3.14'15'92'65'35; 
	static constexpr float  fEPSILON = 1E-6f; 
	static constexpr double dEPSILON = 1E-9; 

	static constexpr float  fSEMICIRCLE_IN_DEGREES = 180.0f;
	static constexpr double dSEMICIRCLE_IN_DEGREES = 180.0;

	// Common math methods
	template<typename T>
	inline T sqr(const T& scalar){
		return scalar * scalar;
	}

	/*inline __attribute__((fastcall)) double& fa_sqrt(const double& scalar){
		asm (
			"fld qword ptr [esp + 0x4]"
			"fsqrt" 
			"ret 0x8"
		);
	}*/

	template<typename T>
	inline const T radian_to_degree(const T& radian){
		return (dSEMICIRCLE_IN_DEGREES / dPI * radian);
	}

	template<>
	inline const float radian_to_degree(const float& radian){
		return (fSEMICIRCLE_IN_DEGREES / fPI * radian);
	}

	template<>
	inline const double radian_to_degree(const double& radian){
		return (dSEMICIRCLE_IN_DEGREES / dPI * radian);
	}

	template<typename T>
	inline const T degree_to_radian(const T& degree){
		return (dPI / dSEMICIRCLE_IN_DEGREES * degree);
	}

	template<>
	inline const float degree_to_radian(const float& degree){
		return (fPI / fSEMICIRCLE_IN_DEGREES * degree);
	}

	template<>
	inline const double degree_to_radian(const double& degree){
		return (dPI / dSEMICIRCLE_IN_DEGREES * degree);
	}

	template<typename T>
	inline const T max(const T& first, const T& second){
		return (first > second) ? first : second;
	}
		
	template<typename T>
	inline const T  min(const T& first, const T& second){
		return (first < second) ? first : second;
	}

	template<typename T>
	inline const bool isEqual(const T& first, const T& second){
		return (first == second) ? true : false;
	}

	template<>
	inline const bool isEqual<float>(const  float&  first, const float&  second){
		return (first - second < FF::fEPSILON) ? true : false;
	}

	template<>
	inline const bool isEqual<double>(const double& first, const double& second){
		return (first - second < FF::dEPSILON) ? true : false;
	}

	template<typename T>
	inline const T clamp(T& first, T& second, T& third){
		return (first > second) ? 
					((second > third) ? second : third) : 
					((first > third)  ? first  : third);
	}
};

#endif // FF_COMMONMATH_HXX_