#include "..\Core\FF_Macros.hxx"

#include "..\Core\FF_CommonMath.hxx"

#include "..\Core\FF_Vector3.hxx"
#include "..\Core\FF_Matrix3x3.hxx"
#include "..\Core\FF_Quaternion.hxx"

#ifndef FF_TRANSFORMS_HXX_
#define FF_TRANSFORMS_HXX_

namespace FF {
    template<typename T>
    class Transforms {
    public:
        /**
         * @brief [Default constructor] 
         * @details [The default construcor aren't defined in FF]
         */
        explicit Transforms(void) = default;


        /**
         * @brief [Method that rotate object about X axis]
         * @details [Rotation represents by multiplying origin matrix on rotate matrix]
         * 
         * @param angleX [The angle of rotation]
         * @param matrix [The matrix, that needed to rotation]
         * @tparam T [Generic type]
         * 
         * @return [Return the new instance of Matrix3x3<T> that represent origin matrix after rotation on angleX about X axis]
         */
        inline FF::Matrix3x3<T> MatrixRotationAboutX(const T& __FF_IN angleX, FF::Matrix3x3<T>& __FF_IN matrix);

        /**
         * @brief [Method that rotate object about Y axis]
         * @details [Rotation represents by multiplying origin matrix on rotate matrix]
         * 
         * @param angleY [The angle of rotation]
         * @param matrix [The matrix, that needed to rotation]
         * @tparam T [Generic type]
         * 
         * @return [Return the new instance of Matrix3x3<T> that represent origin matrix after rotation on angleY about Y axis]
         */
        inline FF::Matrix3x3<T> MatrixRotationAboutY(const T& __FF_IN angleY, FF::Matrix3x3<T>& __FF_IN matrix);

        /**
         * @brief [Method that rotate object about Z axis]
         * @details [Rotation represents by multiplying origin matrix on rotate matrix]
         * 
         * @param angleZ [The angle of rotation]
         * @param matrix [The matrix, that needed to rotation]
         * @tparam T [Generic type]
         * 
         * @return [Return the new instance of Matrix3x3<T> that represent origin matrix after rotation on angleZ about Z axis]
         */
        inline FF::Matrix3x3<T> MatrixRotationAboutZ(const T& __FF_IN angleZ, FF::Matrix3x3<T>& __FF_IN matrix);


        /**
         * @brief [Method that rotate object by quaternion]
         * @details [-]
         * 
         * @param vec [Object that needed to rotate]
         * @param quat [Quaternion that represent orientation in 3D space]
         * @tparam T [Generic type]
         * 
         * @return [Return the new instance of Vector3<T> that represent origin vector after rotation]
         */
        inline FF::Vector3<T>   RotateVectorByQuaternion(const FF::Vector3<T>& __FF_IN vec, const FF::Quaternion<T>& __FF_IN quat);


        /**
         * @brief [Method that scale object]
         * @details [-]
         * 
         * @param scalingX [Coefficient of scaling by X axis]
         * @param scalingY [Coefficient of scaling by Y axis]
         * @param scalingZ [Coefficient of scaling by Z axis]
         * @param matrix [Origin object]
         * @tparam T [Generic type]
         * 
         * @return [Return the new instance of Matrix3x3<T> that represent origin matrix after scaling]
         */
        inline FF::Matrix3x3<T> Scaling(const T& __FF_IN scalingX, const T& __FF_IN scalingY, const T& __FF_IN scalingZ, const __FF_IN FF::Matrix3x3<T>& matrix);

        /**
         * @brief [Method that skew object]
         * @details [Method skew object on ANGLE along the direction VECTOR1 based on the projected length along the direction VECTOR2]
         * 
         * @param angle [Angle]
         * @param vector1 [First vector]
         * @param vector2 [Second vector]
         * @tparam T [Generic type]
         * 
         * @return [Return the new instance of Matrix3x3<T> that represent skew matrix]
         */
        inline FF::Matrix3x3<T> Skew(const T& __FF_IN angle, const FF::Vector3<T>& __FF_IN vector1, const FF::Vector3<T>& __FF_IN vector2);


        /**
         * @brief [Default sectructor]
         */
        ~Transforms(void) = default;
    };

    template<typename T>
    inline FF::Matrix3x3<T> FF::Transforms<T>::MatrixRotationAboutX(const T& __FF_IN angleX, FF::Matrix3x3<T>& __FF_IN matrix){
        return matrix * FF::Matrix3x3<T>( 1.0,         0.0,          0.0,
                                          0.0, cos(angleX), -sin(angleX),
                                          0.0, sin(angleX),  cos(angleX) );
    }

    template<typename T>
    inline FF::Matrix3x3<T> MatrixRotationAboutY(const T& __FF_IN angleY, FF::Matrix3x3<T>& __FF_IN matrix){
        return matrix * FF::Matrix3x3<T>(  cos(angleY), 0x0, sin(angleY),
                                                   0x0, 0x1,         0x0,
                                          -sin(angleY), 0x0, cos(angleY) );
    }

    template<typename T>
    inline FF::Matrix3x3<T> MatrixRotationAboutZ(const T& __FF_IN angleZ, FF::Matrix3x3<T>& __FF_IN matrix){
        return matrix * FF::Matrix3x3<T>( cos(angleZ), -sin(angleZ), 0x0,
                                          sin(angleZ),  cos(angleZ), 0x0,
                                                  0x0,          0x0, 0x1 );
    }

    template<typename T>
    inline FF::Vector3<T> RotateVectorByQuaternion(const FF::Vector3<T>& __FF_IN vec, const FF::Quaternion<T>& __FF_IN quat){
        constexpr FF::Vector3<T>& tmp_vec = quat.GetVectorPart();
        return (vec * (FF::sqr(quat.GetWComponent() - FF::Magnitude(tmp_vec))) + 
                tmp_vec * (FF::DotProduct(vec, tmp_vec) * 2.0f) 
                + FF::CrossProduct(tmp_vec, vec) * (quat.GetWComponent() * 2.0f));
    }

    template<typename T>
    inline FF::Matrix3x3<T> Scaling(const T& __FF_IN scalingX, const T& __FF_IN scalingY, const T& __FF_IN scalingZ, const FF::Matrix3x3<T>& __FF_IN matrix){
        return matrix * FF::Matrix3x3<T>( scalingX,      0x0,        0x0,
                                               0x0, scalingY,        0x0,
                                               0x0,      0x0,   scalingZ );
    }

    template<typename T>
    inline FF::Matrix3x3<T> Skew(const T& __FF_IN angle, const FF::Vector3<T>& __FF_IN vector1, const FF::Vector3<T>& __FF_IN vector2){
        angle = tan(angle);
        T x = vector1.GetXComponent() * angle;
        T y = vector1.GetYComponent() * angle;
        T z = vector1.GetZComponent() * angle;

        return FF::Matrix3x3<T>( x * vector2.GetXComponent() + 0x1, x * vector2.GetYComponent(),        x * vector2.GetZComponent(),
                                 y * vector2.GetXComponent(),       y * vector2.GetYComponent() + 0x1,  y * vector2.GetZComponent(),
                                 z * vector2.GetXComponent(),       z * vector2.GetYComponent(),        z * vector2.GetZComponent() + 0x1 );
    }
};

#endif // FF_TRANSFORMS_HXX_