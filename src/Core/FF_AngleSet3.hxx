#include "FF_Macros.hxx"
#include "FF_CommonMath.hxx"

#ifndef FF_ANGLESET3_HXX_
#define FF_ANGLESET3_HXX_

namespace FF {
    /**
     * @brief [Class that represent set of angle in 3D]
     * @details [long description]
     * 
     * @tparam T [description]
     */
    template<typename T>
    class AngleSet3 {
    private:
        T m_XRotationAngle;
        T m_YRotationAngle;
        T m_ZRotationAngle;

        T CheckAngle(const T __FF_IN angle);
    public:
        /**
         * @brief [Default constructor]
         * @details [Default constructor aren't defined in FF]
         */
        explicit AngleSet3(void) = delete;
        
        /**
         * @brief [Constructor with parameters]
         * @details [Instance object from scalar types that represent angles of rotation by axis]
         * 
         * @param xRotation [X angle]
         * @param yRotation [Y angle]
         * @param zRotation [Z angle]
         */
        explicit AngleSet3( T __FF_IN xRotation = static_cast<T>(0.0f),
                            T __FF_IN yRotation = static_cast<T>(0.0f),
                            T __FF_IN zRotation = static_cast<T>(0.0f) )
        : m_XRotationAngle(xRotation),
          m_YRotationAngle(yRotation),
          m_ZRotationAngle(zRotation) {}

        /**
         * @brief [Copy constructor]
         * @details [Instance object from ANGLE_SET]
         * 
         * @param angleSet [Another ANGLE_SET object]
         */
        explicit AngleSet3(const FF::AngleSet3<T>& angleSet);
        
        /**
         * @brief [Method that set X angle]
         * @details [-]
         * 
         * @param xRotation [X angle]
         */
        inline void SetXAngle(const T __FF_IN xRotation);

        /**
         * @brief [Method that get X angle]
         * @details [-]
         * 
         * @param xRotation [X angle]
         */
        inline T    GetXAngle(void) const;

        /**
         * @brief [Method that set Y angle]
         * @details [-]
         * 
         * @param xRotation [Y angle]
         */
        inline void SetYAngle(const T __FF_IN yRotation);

        /**
         * @brief [Method that get Y angle]
         * @details [Const method]
         * 
         * @param xRotation [Y angle]
         */
        inline T    GetYAngle(void) const;

        /**
         * @brief [Method that set Z angle]
         * @details [-]
         * 
         * @param xRotation [Z angle]
         */
        inline void SetZAngle(const T __FF_IN zRotation);

        /**
         * @brief [Method that get Z angle]
         * @details [Const method]
         * 
         * @param xRotation [Z angle]
         */
        inline T    GetZAngle(void) const;


        /**
         * @brief [Method that set X, Y and Z component]
         * @details [-]
         * 
         * @param xRotation [X angle]
         * @param yRotation [Y angle]
         * @param zRotation [Z angle]
         */
        inline void SetXYZ(const T __FF_IN xRotation, const T __FF_IN yRotation, const T __FF_IN zRotation);

        /**
         * @brief [OVerloaded operator '=']
         * @details [Used for set XYZ in values that have parameter]
         * 
         * @param rhs [Angle set with needed values on components]
         */
        inline FF::AngleSet3<T>& operator=(const FF::AngleSet3<T>& rhs);

        /**
         * @brief [Default destructor]
         */
        ~AngleSet(void) = default;
    };

    template<typename T>
    FF::AngleSet3<T>::AngleSet3(const FF::AngleSet3<T>& __FF_IN angleSet) {
        this->m_XRotationAngle = angleSet.GetXAngle();
        this->m_YRotationAngle = angleSet.GetYAngle();
        this->m_ZRotationAngle = angleSet.GetZAngle();
    }
        
    template<typename T>
    inline void FF::AngleSet3<T>::SetXAngle(const T __FF_IN xRotation){
        this->m_XRotationAngle = xRotation;
    }

    template<typename T>
    inline T FF::AngleSet3<T>::GetXAngle(void) const {
        return this->m_XRotationAngle;
    }

    template<typename T>
    inline void FF::AngleSet3<T>::SetYAngle(const T __FF_IN yRotation){
        this->m_YRotationAngle = yRotation;
    }

    template<typename T>
    inline T FF::AngleSet3<T>::GetYAngle(void) const {
        return this->m_YRotationAngle;
    }

    template<typename T>
    inline void FF::AngleSet3<T>::SetZAngle(const T __FF_IN zRotation){
        this->m_ZRotationAngle = zRotation;
    }

    template<typename T>
    inline T FF::AngleSet3<T>::GetZAngle(void) const {
        return this->m_ZRotationAngle;
    }

    template<typename T>
    inline void FF::AngleSet3<T>::SetXYZ(const T __FF_IN xRotation, const T __FF_IN yRotation, const T __FF_IN zRotation){
        this->m_XRotationAngle = xRotation;
        this->m_YRotationAngle = yRotation;
        this->m_ZRotationAngle = zRotation;
    }

    template<typename T>
    inline FF::AngleSet3<T>& FF::AngleSet3<T>::operator=(const FF::AngleSet3<T>& rhs){
        this->SetXAngle(rhs.GetXAngle());
        this->SetYAngle(rhs.GetYAngle());
        this->SetZAngle(rhs.GetZAngle());

        return (*this);
    }

    template<typename T>
    inline T FF::AngleSet3<T>::CheckAngle(const T __FF_IN angle){
        T tmpAngle = angle;
        tmpAngle = FF::abs(tmpAngle);
        
        while (tmpAngle > 0x2 * FF::dPI) {
            tmpAngle -= 0x2 * FF::dPI;
        }

        // If the new angle is negative, put the negative sign back on
        tmpAngle = FF::abs(tmpAngle);

        return tmpAngle;
    }
};

#endif // FF_ANGLESET3_HXX_