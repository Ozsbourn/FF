#include "FF_Macros.hxx"

#include "FF_Vector3.hxx"
#include "FF_Vector4.hxx"

#include "FF_Matrix3x3.hxx"

#ifndef FF_QUATERNION_HXX_
#define FF_QUATERNION_HXX_

namespace FF {
	/**
	 * @brief [Class that represent quaternion entity]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Quaternion {
	private:
		T m_x;
		T m_y;
		T m_z;
		T m_w;
	public:
		/**
		 * @brief [Default constructor]
		 * @details [Default constructor aren't defined in FF]
		 */
		explicit Quaternion(void) = delete;

		/**
		 * @brief [Constructor with parameters]
		 * @details [Set all components in appropriate with scalar values]
		 * 
		 * @param x [X component]
		 * @param y [Y component]
		 * @param y [Z component]
		 * @param w [W component]
		 */
		explicit Quaternion( T __FF_IN x = static_cast<T>(0.0f),
				             T __FF_IN y = static_cast<T>(0.0f),
				             T __FF_IN z = static_cast<T>(0.0f),
				             T __FF_IN w = static_cast<T>(0.0f) )
		: m_x(x), 
		  m_y(y), 
		  m_y(z), 
		  m_y(w) {}

		/**
		 * @brief [Constructor with parameters]
		 * @details [Set all components in appropriate with vec components and scalar values]
		 * 
		 * @param vec [Vector]
		 * @param scalar [Scalar value]
		 */
		explicit Quaternion( FF::Vector3<T>& __FF_IN vec,
				             T               __FF_IN scalar );

		/**
		 * @brief [Constructor with parameters]
		 * @details [Set all components in appropriate with vec components]
		 * 
		 * @param vec [Vector]
		 */
		explicit Quaternion( FF::Vector4<T>& __FF_IN vec );

		/**
		 * @brief [Overloaded operator '*']
		 * @details [Define mul operation to quaternion]
		 * 
		 * @param quat1 [First quaternion]
		 * @param quat2 [Second quaternion]
		 * @tparam U [Generic type]
		 * @return [Return instance of quaternion that represent mul of origin quaternions]
		 */
		template<typename U>
		friend inline FF::Quaternion<U> operator*(const FF::Quaternion<U>& __FF_IN quat1, const FF::Quaternion<U>& __FF_IN quat2);

		/**
		 * @brief [Method that get vector part of quaternion]
		 * @details [X, Y and Z components are vector part]
		 * @return [Return VEC3 with X, Y and Z components from origin quaternion]
		 */
		inline const FF::Vector3<T>& GetVectorPart(void) const;

		/**
		 * @brief [Method that get rotation matrix by quaternion]
		 * @details [Const method]
		 * @return [Return rotation MAT3]
		 */
		inline FF::Matrix3x3<T>& GetRotationMatrix(void) const;

		/**
		 * @brief [Method that set rotation matrix]
		 * @details [-]
		 * 
		 * @param matrix [Matrix]
		 */
		inline void 			 SetRotationMatrix(FF::Matrix3x3<T>& __FF_OUT matrix);

		/**
		 * @brief [Default destructor]
		 */
		~Quaternion(void) = default;
	};

	template<typename T>
	FF::Quaternion<T>::Quaternion( FF::Vector3<T>& vec,
				 		           T               scalar ) {
		this->m_x = vec.GetXComponent();
		this->m_y = vec.GetYComponent();
		this->m_z = vec.GetZComponent();
		this->m_w = scalar;
	}

	template<typename T>
	FF::Quaternion<T>::Quaternion( FF::Vector4<T>& vec ){
		this->m_x = vec.GetXComponent();
		this->m_y = vec.GetYComponent();
		this->m_z = vec.GetZComponent();
		this->m_w = vec.GetWComponent();
	}

	template<typename T>
	inline FF::Quaternion<T> operator*(const FF::Quaternion<T>& quat1, const FF::Quaternion<T>& quat2){
		return FF::Quaternion<T>( quat1.m_w * quat2.x + quat1.m_x * quat2.m_w + quat1.m_y * quat2.m_z - quat1.m_z * quat2.m_y, 
								  quat1.m_w * quat2.y - quat1.m_x * quat2.m_z + quat1.m_y * quat2.m_w + quat1.m_z * quat2.m_x, 
								  quat1.m_w * quat2.z + quat1.m_x * quat2.m_y - quat1.m_y * quat2.m_x + quat1.m_z * quat2.m_w, 
								  quat1.m_w * quat2.w - quat1.m_x * quat2.m_x - quat1.m_y * quat2.m_y - quat1.m_z * quat2.m_z );
	}

	template<typename T>
	inline const FF::Vector3<T>& FF::Quaternion<T>::GetVectorPart(void) const {
		return FF::Vector3<T>( this->m_x, this->m_y, this->m_z );
	}

	template<typename T>
	inline FF::Matrix3x3<T>& FF::Quaternion<T>::GetRotationMatrix(void) const {
		T xx = FF::sqr(this->m_x);
		T yy = FF::sqr(this->m_y);
		T zz = FF::sqr(this->m_z);
		T xy = this->m_x * this->m_y;
		T xz = this->m_x * this->m_z;
		T yz = this->m_y * this->m_z;
		T wx = this->m_w * this->m_x;
		T wy = this->m_w * this->m_y;
		T wz = this->m_w * this->m_z;

		return FF::Matrix3x3<T>( 1.0f - 2.0f * (yy + zz), 2.0f * (xy - wz),        2.0f * (xz + wy), 
								 2.0f * (xy + wz),        1.0f - 2.0f * (xx + zz), 2.0f * (yz - wx),
								 2.0f * (xz - xy), 	      2.0f * (yz + wx),        1.0f - 2.0f * (xx + yy) );
	}

	template<typename T>
	inline void 			 FF::Quaternion<T>::SetRotationMatrix(FF::Matrix3x3<T>& matrix){
		constexpr T m00 = matrix(0, 0);
		constexpr T m11 = matrix(1, 1);
		constexpr T m22 = matrix(2, 2);
		constexpr T sum = m00 + m11 + m22;

		if (sum > 0.0f) {
			this->m_w = sqrt(sum + 1.0f) * 0.5f;
			constexpr float f = 0.25f / this->m_w;

			this->m_x = (matrix(2, 1) - matrix(1, 2)) * f;
			this->m_y = (matrix(0, 2) - matrix(2, 0)) * f;
			this->m_z = (matrix(1, 0) - matrix(0, 1)) * f;
		} else if ((m00 > m11) && (m00 > m22)) {
			this->m_x = sqrt(m00 - m11 - m22 + 1.0f) * 0.5f;
			constexpr float f = 0.25f / this->m_x; 

			this->m_x = (matrix(1, 0) - matrix(0, 1)) * f;
			this->m_y = (matrix(0, 2) - matrix(2, 0)) * f;
			this->m_z = (matrix(2, 1) - matrix(1, 2)) * f;
		} else if (m11 > m22) {
			this->m_y = sqrt(m00 - m11 - m22 + 1.0f) * 0.5f;
			constexpr float f = 0.25f / this->m_y;

			this->m_x = (matrix(1, 0) - matrix(0, 1)) * f;
			this->m_y = (matrix(2, 1) - matrix(1, 2)) * f;
			this->m_z = (matrix(0, 2) - matrix(2, 0)) * f;
		} else {
			this->m_z = sqrt(m00 - m11 - m22 + 1.0f) * 0.5f;
			constexpr float f = 0.25f / this->m_z;

			this->m_x = (matrix(0, 2) - matrix(2, 0)) * f;
			this->m_y = (matrix(2, 1) - matrix(1, 2)) * f;
			this->m_z = (matrix(1, 0) - matrix(0, 1)) * f;
		}
	}
};

#endif // FF_QUATERNION_HXX_