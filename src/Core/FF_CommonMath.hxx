#ifndef FF_COMMONMATH_HXX_
#define FF_COMMONMATH_HXX_

namespace FF {
    // Constants

    /**
     * PI with float type (After 6 digit after point accuracy is lost)
     */
    static constexpr float  fPI      = 3.14'15'92f;
    static constexpr double dPI      = 3.14'15'92'65'35; 
    /**
     * EPSILON is small number needed to comparisson number with float point
     */
    static constexpr float  fEPSILON = 1E-6f; 
    static constexpr double dEPSILON = 1E-9; 

    /**
     * Value of semicircle in degrees
     */
    static constexpr float  fSEMICIRCLE_IN_DEGREES = 180.0f;
    static constexpr double dSEMICIRCLE_IN_DEGREES = 180.0;

    // Common math methods

    /**
     * @brief [Method that calculate abs of numbers of generic types]
     * @details [-]
     * 
     * @param value [Number]
     * @tparam T [Generic type]
     * @return [Return absolute value of parameter]
     */
    template<typename T>
    inline const T abs(const T value){
        // Set high bit in 0 value which represent in integer numbers positive numbers
        return (value & (0x0 << (0x8 * sizeof(value) - 0x1)));
    }

    /**
     * @brief [Method that calculate abs of numbers of float types]
     * @details [Specify abs to float type]
     * 
     * @param value [Number (float type)]
     * @return [Return absolute value of parameter]
     */
    template<>
    inline const float abs<float>(const float value){
        return (value >= 0.0f) ? value : -value ;
    }

    /**
     * @brief [Method that calculate abs of numbers of double types]
     * @details [Specify abs to double type]
     * 
     * @param value [Number (double type)]
     * @return [Return absolute value of parameter]
     */
    template<>
    inline const double abs<double>(const double value){
        return (value >= 0.0) ? value : -value ;
    }

    /**
     * @brief [Method that calculate square of number]
     * @details [-]
     * 
     * @param scalar [Number]
     * @tparam T [Generic type]
     * @return [Return square root of value got in parameters]
     */
    template<typename T>
    inline T sqr(const T& scalar){
        return scalar * scalar;
    }

    /**
     * @brief [Method for calculate fast square root]
     * @details [Defined for double type]
     * 
     * @param scalar [Number]
     * @return [Return square root]
     */
    inline __attribute__((fastcall)) double& fa_sqrt(const double& scalar){
        asm (
            "fld qword ptr [esp + 0x4]"
            "fsqrt" 
            "ret 0x8"
        );
    }

    /**
     * @brief [Method that translate radian to degrees]
     * @details [-]
     * 
     * @param radian [Radian value]
     * @tparam T [Generic type]
     * @return [Return value of degrees that equal to radians got in parameters]
     */
    template<typename T>
    inline const T radian_to_degree(const T& radian){
        return (dSEMICIRCLE_IN_DEGREES / dPI * radian);
    }

    /**
     * @brief [Method that translate radian to degrees]
     * @details [Specify to float]
     * 
     * @param radian [Radian value]
     * @return [Return value of degrees that equal to radians got in parameters]
     */
    template<>
    inline const float radian_to_degree(const float& radian){
        return (fSEMICIRCLE_IN_DEGREES / fPI * radian);
    }

    /**
     * @brief [Method that translate radian to degrees]
     * @details [Specify to double]
     * 
     * @param radian [Radian value]
     * @return [Return value of degrees that equal to radians got in parameters]
     */
    template<>
    inline const double radian_to_degree(const double& radian){
        return (dSEMICIRCLE_IN_DEGREES / dPI * radian);
    }

    /**
     * @brief [Method that translate degrees to radians]
     * @details [-]
     * 
     * @param radian [Degree value]
     * @tparam T [Generic type]
     * @return [Return value of radians that equal to degrees got in parameters]
     */
    template<typename T>
    inline const T degree_to_radian(const T& degree){
        return (dPI / dSEMICIRCLE_IN_DEGREES * degree);
    }

    /**
     * @brief [Method that translate degrees to radians]
     * @details [Specify to float]
     * 
     * @param radian [Degree value]
     * @return [Return value of radians that equal to degrees got in parameters]
     */
    template<>
    inline const float degree_to_radian(const float& degree){
        return (fPI / fSEMICIRCLE_IN_DEGREES * degree);
    }

    /**
     * @brief [Method that translate degrees to radians]
     * @details [Specify to double]
     * 
     * @param radian [Degree value]
     * @return [Return value of radians that equal to degrees got in parameters]
     */
    template<>
    inline const double degree_to_radian(const double& degree){
        return (dPI / dSEMICIRCLE_IN_DEGREES * degree);
    }

    /**
     * @brief [Method that find max in two numbers]
     * @details [-]
     * 
     * @param first [First number]
     * @param second [Second number]
     * @tparam T [Generic type]
     * @return [Return max of two numbers]
     */
    template<typename T>
    inline const T max(const T& first, const T& second){
        return (first > second) ? first : second;
    }
        
    /**
     * @brief [Method that find min in two numbers]
     * @details [-]
     * 
     * @param first [First number]
     * @param second [Second number]
     * @tparam T [Generic type]
     * @return [Return min of two numbers]
     */
    template<typename T>
    inline const T  min(const T& first, const T& second){
        return (first < second) ? first : second;
    }

    /**
     * @brief [Method that check that two parameters are equal]
     * @details [-]
     * 
     * @param first [First number]
     * @param second [Second number]
     * @tparam T [Generic type]
     * 
     * @return [Return true if two values are equal and false in another case]
     */
    template<typename T>
    inline const bool isEqual(const T& first, const T& second){
        return (first == second) ? true : false;
    }

    /**
     * @brief [Method that check that two parameters are equal]
     * @details [Specify to float]
     * 
     * @param first [First number]
     * @param second [Second number]
     * 
     * @return [Return true if two values are equal and false in another case]
     */
    template<>
    inline const bool isEqual<float>(const  float&  first, const float&  second){
        return (first - second < FF::fEPSILON) ? true : false;
    }

    /**
     * @brief [Method that check that two parameters are equal]
     * @details [Specify to double]
     * 
     * @param first [First number]
     * @param second [Second number]
     * 
     * @return [Return true if two values are equal and false in another case]
     */
    template<>
    inline const bool isEqual<double>(const double& first, const double& second){
        return (first - second < FF::dEPSILON) ? true : false;
    }

    /**
     * @brief [Method that check that parameter close to zero or not]
     * @details [-]
     * 
     * @param value [Value]
     * @tparam T [Generic type]
     * 
     * @return [Return true if value close to zero or not in another case]
     */
    template<typename T>
    inline const bool CloseToZero(const T value){
        return (FF::abs(value) <= 0x1) ? true : false ;
    }

    /**
     * @brief [Method that check that parameter close to zero or not]
     * @details [Specify to float]
     * 
     * @param value [Value]
     * 
     * @return [Return true if value close to zero or not in another case]
     */
    template<>
    inline const bool CloseToZero<float>(const float value){
        return (FF::abs(value) <= FF::fEPSILON) ? true : false ;
    }

    /**
     * @brief [Method that check that parameter close to zero or not]
     * @details [Specify to double]
     * 
     * @param value [Value]
     * 
     * @return [Return true if value close to zero or not in another case]
     */
    template<>
    inline const bool CloseToZero<double>(const double value){
        return (FF::abs(value) <= FF::dEPSILON) ? true : false ;
    }

    /**
     * @brief [Method that find clamp in three numbers]
     * @details [-]
     * 
     * @param first [First number]
     * @param second [Second number]
     * @param third [Third number]
     * 
     * @tparam T [Generic type]
     * 
     * @return [Return not max and not min value]
     */
    template<typename T>
    inline const T clamp(T& first, T& second, T& third){
        return (first > second) ? 
                    ((second > third) ? second : third) : 
                    ((first > third)  ? first  : third);
    }
};

#endif // FF_COMMONMATH_HXX_