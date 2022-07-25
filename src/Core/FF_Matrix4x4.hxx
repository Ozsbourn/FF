#include "FF_Macros.hxx"
#include "FF_Vector4.hxx"

#ifndef FF_MATRIX4X4_HXX_
#define FF_MATRIX4X4_HXX_

namespace FF {
	/**
	 * @brief [Class that represent four-dimensional matrix]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Matrix4x4 {
	private:
		T m_mat[0x4][0x4];
	public:
		/**
		 * @brief [Default constructor are not defined to all entities in FF]
		 */
		explicit Matrix4x4(void) = delete;

		/**
		 * @brief [Constuctor with the parameters that have init MAT4 with scalar values]
		 * 
		 * @param v11 [Value with index (0,0)]
		 * @param v12 [Value with index (0,1)]
		 * @param v13 [Value with index (0,2)]
		 * @param v14 [Value with index (0,3)]
		 * 
		 * @param v21 [Value with index (1,0)]
		 * @param v22 [Value with index (1,1)]
		 * @param v23 [Value with index (1,2)]
		 * @param v24 [Value with index (1,3)]
		 * 
		 * @param v31 [Value with index (2,0)]
		 * @param v32 [Value with index (2,1)]
		 * @param v33 [Value with index (2,2)]
		 * @param v34 [Value with index (2,3)]
		 * 
		 * @param v41 [Value with index (3,0)]
		 * @param v42 [Value with index (3,1)]
		 * @param v43 [Value with index (3,2)]
		 * @param v44 [Value with index (3,3)]
		 */
		explicit Matrix4x4(	T __FF_IN v11 = static_cast<T>(0.0f), T __FF_IN v12 = static_cast<T>(0.0f), T __FF_IN v13 = static_cast<T>(0.0f), T __FF_IN v14 = static_cast<T>(0.0f),
							T __FF_IN v21 = static_cast<T>(0.0f), T __FF_IN v22 = static_cast<T>(0.0f), T __FF_IN v23 = static_cast<T>(0.0f), T __FF_IN v24 = static_cast<T>(0.0f),
							T __FF_IN v31 = static_cast<T>(0.0f), T __FF_IN v32 = static_cast<T>(0.0f), T __FF_IN v33 = static_cast<T>(0.0f), T __FF_IN v34 = static_cast<T>(0.0f),
							T __FF_IN v41 = static_cast<T>(0.0f), T __FF_IN v42 = static_cast<T>(0.0f), T __FF_IN v43 = static_cast<T>(0.0f), T __FF_IN v44 = static_cast<T>(0.0f) )
		: m_mat{ v11, v12, v13, v14,
		 		 v21, v22, v23, v24,
		 		 v31, v32, v33, v34,
		 		 v41, v42, v43, v44 } {}

		/**
		 * @brief [Constuctor with the parameters that have init MAT4 with vectors]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @param vec3 [Third vector]
		 * @param vec4 [Fourth vector]
		 */
		explicit Matrix4x4( FF::Vector4<T>& __FF_IN vec1,
							FF::Vector4<T>& __FF_IN vec2,
							FF::Vector4<T>& __FF_IN vec3,
							FF::Vector4<T>& __FF_IN vec4 );

		/**
		 * @brief [Friend function that instance identity matrix]
		 * @details [ [1 0 0 0],
		 * 			  [0 1 0 0],
		 * 			  [0 0 1 0],
		 * 			  [0 0 0 1] ]
		 * @return [Return identity matrix]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U>& Identity(void);


		/**
		 * @brief [Operator that calculate difference of this matrix and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator-=(const T& __FF_IN scalar);

		/**
		 * @brief [Operator that calculate sum of this matrix and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator+=(const T& __FF_IN scalar);

		/**
		 * @brief [Operator that calculate mul of this matrix and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator*=(const T& __FF_IN scalar);

		/**
		 * @brief [Operator that calculate div of this matrix and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator/=(const T& __FF_IN scalar);


		/**
		 * @brief [Operator that calculate dif with this matrix and parameter matrix]
		 * @details [-]
		 * 
		 * @param vec [Matrix]
		 */
		inline void operator-=(const FF::Matrix4x4<T>& __FF_IN mat);

		/**
		 * @brief [Operator that calculate sum with this matrix and parameter matrix]
		 * @details [-]
		 * 
		 * @param vec [Matrix]
		 */
		inline void operator+=(const FF::Matrix4x4<T>& __FF_IN mat);


		/**
		 * @brief [Friend function that return -mat]
		 * @details [Apply '-' to each component]
		 * 
		 * @param mat [Matrix]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent origin matrix with other sign]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator-(const FF::Matrix4x4<U>& __FF_IN mat);

		/**
		 * @brief [Friend function that calculate difference of two mats]
		 * @details [Each component is difference of appropriate components of parameter matrix]
		 * 
		 * @param mat1 [First matrix]
		 * @param mat2 [Second matrix]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent difference of two matrix]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator-(const FF::Matrix4x4<U>& __FF_IN mat1, const FF::Matrix4x4<U>& __FF_IN mat2);

		/**
		 * @brief [Friend function that calculate sum of two mats]
		 * @details [Each component is sum of appropriate components of parameter matrix]
		 * 
		 * @param mat1 [First matrix]
		 * @param mat2 [Second matrix]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent sum of two matrix]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator+(const FF::Matrix4x4<U>& __FF_IN mat1, const FF::Matrix4x4<U>& __FF_IN mat2);
		
		/**
		 * @brief [Friend function that calculate mul of two mats]
		 * @details [Each component is mul of appropriate components of appropriate row and column]
		 * 
		 * @param mat1 [First matrix]
		 * @param mat2 [Second matrix]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent mul of two matrix]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator*(const FF::Matrix4x4<U>& __FF_IN mat1, const FF::Matrix4x4<U>& __FF_IN mat2);


		/**
		 * @brief [Friend function that calculate mul of vec and mat]
		 * @details [Each component is mul of appropriate components of appropriate row and column]
		 * 
		 * @param mat [Matrix]
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent vec * mat]
		 */
		template<typename U>
		friend inline FF::Vector4<U>   operator*(const FF::Matrix4x4<U>& __FF_IN mat,  const FF::Vector4<U>& __FF_IN vec);


		/**
		 * @brief [Friend function that calculate difference of mat and scalar]
		 * @details [Each component is difference of appropriate components of parameter matrix]
		 * 
		 * @param mat [Matrix]
		 * @param scalar [Scalar value]
		 * @tparam U [Generic type]
		 * @return [Return matrix that mat - scalar]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator-(const FF::Matrix4x4<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate sum of matrix and scalar]
		 * @details [Each component is sum of appropriate components origin vectors]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent sum of origin vectors]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator+(const FF::Matrix4x4<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate composition mat and scalar value]
		 * @details [Each component mul to scalar]
		 * 
		 * @param mat [Vector]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent mul of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator*(const FF::Matrix4x4<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate division matrix and scalar value]
		 * @details [Each component divide to scalar]
		 * 
		 * @param mat [Matrix]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent div of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix4x4<U> operator/(const FF::Matrix4x4<U>& __FF_IN mat,  const U& __FF_IN scalar);


		/**
		 * @brief [Method that return row of matrix such a vector]
		 * @details [-]
		 * 
		 * @param index [Index of row]
		 * @return [Return vector]
		 */
		inline FF::Vector4<T> operator[](const std::size_t& __FF_IN rowNumber);

		
		/**
		 * @brief [Debug override << operator]
		 * @details [Used for output values in ostream. Friend function]
		 * 
		 * @param out [Out stream]
		 * @param m [Matrix]
		 */
		template<typename U>
		friend inline std::ostream& operator<<(std::ostream& __FF_OUT out, const FF::Matrix4x4<U>& __FF_IN m);

		/**
		 * @brief [Default destructor]
		 * @details [-]
		 */
		~Matrix4x4(void) = default;
	};

	template<typename T>
	FF::Matrix4x4<T>::Matrix4x4( FF::Vector4<T>& __FF_IN vec1,
						 	     FF::Vector4<T>& __FF_IN vec2,
						 	     FF::Vector4<T>& __FF_IN vec3,
						 	     FF::Vector4<T>& __FF_IN vec4 )
	: m_mat{ vec1.getXComponent(), vec1.getYComponent(), vec1.GetZComponent(), vec1.GetWComponent(),
		 	 vec2.getXComponent(), vec2.getYComponent(), vec2.GetZComponent(), vec2.GetWComponent(),
		 	 vec3.getXComponent(), vec3.getYComponent(), vec3.GetZComponent(), vec3.GetWComponent(),
		 	 vec4.getXComponent(), vec4.getYComponent(), vec4.GetZComponent(), vec4.GetWComponent() } {}

	template<typename T>
	inline FF::Matrix4x4<T>& Identity(void){
		return FF::Matrix4x4<T>( static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
				  		  	     static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
				  		   		 static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
				  		   		 static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f) );
	}

	template<typename T>
	inline void FF::Matrix4x4<T>::operator-=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] -= scalar; this->m_mat[0x0][0x1] -= scalar; this->m_mat[0x0][0x2] -= scalar; this->m_mat[0x0][0x3] -= scalar;
		this->m_mat[0x1][0x0] -= scalar; this->m_mat[0x1][0x1] -= scalar; this->m_mat[0x1][0x2] -= scalar; this->m_mat[0x1][0x3] -= scalar;
		this->m_mat[0x2][0x0] -= scalar; this->m_mat[0x2][0x1] -= scalar; this->m_mat[0x2][0x2] -= scalar; this->m_mat[0x2][0x3] -= scalar;
		this->m_mat[0x3][0x0] -= scalar; this->m_mat[0x3][0x1] -= scalar; this->m_mat[0x3][0x2] -= scalar; this->m_mat[0x3][0x3] -= scalar;
	}

	template<typename T>
	inline void FF::Matrix4x4<T>::operator+=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] += scalar; this->m_mat[0x0][0x1] += scalar; this->m_mat[0x0][0x2] += scalar; this->m_mat[0x0][0x3] += scalar;
		this->m_mat[0x1][0x0] += scalar; this->m_mat[0x1][0x1] += scalar; this->m_mat[0x1][0x2] += scalar; this->m_mat[0x1][0x3] += scalar;
		this->m_mat[0x2][0x0] += scalar; this->m_mat[0x2][0x1] += scalar; this->m_mat[0x2][0x2] += scalar; this->m_mat[0x2][0x3] += scalar;
		this->m_mat[0x3][0x0] += scalar; this->m_mat[0x3][0x1] += scalar; this->m_mat[0x3][0x2] += scalar; this->m_mat[0x3][0x3] += scalar;
	}

	template<typename T>
	inline void FF::Matrix4x4<T>::operator*=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] *= scalar; this->m_mat[0x0][0x1] *= scalar; this->m_mat[0x0][0x2] *= scalar; this->m_mat[0x0][0x3] *= scalar;
		this->m_mat[0x1][0x0] *= scalar; this->m_mat[0x1][0x1] *= scalar; this->m_mat[0x1][0x2] *= scalar; this->m_mat[0x1][0x3] *= scalar;
		this->m_mat[0x2][0x0] *= scalar; this->m_mat[0x2][0x1] *= scalar; this->m_mat[0x2][0x2] *= scalar; this->m_mat[0x2][0x3] *= scalar;
		this->m_mat[0x3][0x0] *= scalar; this->m_mat[0x3][0x1] *= scalar; this->m_mat[0x3][0x2] *= scalar; this->m_mat[0x3][0x3] *= scalar;
	}

	template<typename T>
	inline void FF::Matrix4x4<T>::operator-=(const FF::Matrix4x4<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] -= mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] -= mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] -= mat.m_mat[0x0][0x2]; this->m_mat[0x0][0x3] -= mat.m_mat[0x0][0x3];
		this->m_mat[0x1][0x0] -= mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] -= mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] -= mat.m_mat[0x1][0x2]; this->m_mat[0x1][0x3] -= mat.m_mat[0x1][0x3];
		this->m_mat[0x2][0x0] -= mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] -= mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] -= mat.m_mat[0x2][0x2]; this->m_mat[0x2][0x3] -= mat.m_mat[0x2][0x3];
		this->m_mat[0x3][0x0] -= mat.m_mat[0x3][0x0]; this->m_mat[0x3][0x1] -= mat.m_mat[0x3][0x1]; this->m_mat[0x3][0x2] -= mat.m_mat[0x3][0x2]; this->m_mat[0x3][0x3] -= mat.m_mat[0x3][0x3];
	}

	template<typename T>
	inline void FF::Matrix4x4<T>::operator+=(const FF::Matrix4x4<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] += mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] += mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] += mat.m_mat[0x0][0x2]; this->m_mat[0x0][0x3] += mat.m_mat[0x0][0x3]; 
		this->m_mat[0x1][0x0] += mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] += mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] += mat.m_mat[0x1][0x2]; this->m_mat[0x1][0x3] += mat.m_mat[0x1][0x3]; 
		this->m_mat[0x2][0x0] += mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] += mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] += mat.m_mat[0x2][0x2]; this->m_mat[0x2][0x3] += mat.m_mat[0x2][0x3]; 
		this->m_mat[0x3][0x0] += mat.m_mat[0x3][0x0]; this->m_mat[0x3][0x1] += mat.m_mat[0x3][0x1]; this->m_mat[0x3][0x2] += mat.m_mat[0x3][0x2]; this->m_mat[0x3][0x3] += mat.m_mat[0x3][0x3];
	}

	template<typename T>
	inline void FF::Matrix4x4<T>::operator/=(const T& __FF_IN scalar){
		T divCoeff = 0x1 / scalar;
		this->m_mat[0x0][0x0] *= divCoeff; this->m_mat[0x0][0x1] *= divCoeff; this->m_mat[0x0][0x2] *= divCoeff; this->m_mat[0x0][0x3] *= divCoeff;
		this->m_mat[0x1][0x0] *= divCoeff; this->m_mat[0x1][0x1] *= divCoeff; this->m_mat[0x1][0x2] *= divCoeff; this->m_mat[0x1][0x3] *= divCoeff;
		this->m_mat[0x2][0x0] *= divCoeff; this->m_mat[0x2][0x1] *= divCoeff; this->m_mat[0x2][0x2] *= divCoeff; this->m_mat[0x2][0x3] *= divCoeff;
		this->m_mat[0x3][0x0] *= divCoeff; this->m_mat[0x3][0x1] *= divCoeff; this->m_mat[0x3][0x2] *= divCoeff; this->m_mat[0x3][0x3] *= divCoeff;
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator-(const FF::Matrix4x4<T>& __FF_IN mat){
		return FF::Matrix4x4<T>( -mat.m_mat[0x0][0x0], -mat.m_mat[0x0][0x1], -mat.m_mat[0x0][0x2], -mat.m_mat[0x0][0x3],
				  		   		 -mat.m_mat[0x1][0x0], -mat.m_mat[0x1][0x1], -mat.m_mat[0x1][0x2], -mat.m_mat[0x1][0x3],
				  		   		 -mat.m_mat[0x2][0x0], -mat.m_mat[0x2][0x1], -mat.m_mat[0x2][0x2], -mat.m_mat[0x2][0x3],
				  		   		 -mat.m_mat[0x3][0x0], -mat.m_mat[0x3][0x1], -mat.m_mat[0x3][0x2], -mat.m_mat[0x3][0x3] );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator-(const FF::Matrix4x4<T>& __FF_IN mat1, const FF::Matrix4x4<T>& __FF_IN mat2){
		return FF::Matrix4x4<T>( mat1.m_mat[0x0][0x0] - mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] - mat2.m_mat[0x0][0x1], mat1.m_mat[0x0][0x2] - mat2.m_mat[0x0][0x2], mat1.m_mat[0x0][0x3] - mat2.m_mat[0x0][0x3],
				  		   		 mat1.m_mat[0x1][0x0] - mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] - mat2.m_mat[0x1][0x1], mat1.m_mat[0x1][0x2] - mat2.m_mat[0x1][0x2], mat1.m_mat[0x1][0x3] - mat2.m_mat[0x1][0x3],
				  		   		 mat1.m_mat[0x2][0x0] - mat2.m_mat[0x2][0x0], mat1.m_mat[0x2][0x1] - mat2.m_mat[0x2][0x1], mat1.m_mat[0x2][0x2] - mat2.m_mat[0x2][0x2], mat1.m_mat[0x2][0x3] - mat2.m_mat[0x2][0x3],
				  		   		 mat1.m_mat[0x3][0x0] - mat2.m_mat[0x3][0x0], mat1.m_mat[0x3][0x1] - mat2.m_mat[0x3][0x1], mat1.m_mat[0x3][0x2] - mat2.m_mat[0x3][0x2], mat1.m_mat[0x3][0x3] - mat2.m_mat[0x3][0x3] );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator+(const FF::Matrix4x4<T>& __FF_IN mat1, const FF::Matrix4x4<T>& __FF_IN mat2){
		return FF::Matrix4x4<T>( mat1.m_mat[0x0][0x0] + mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] + mat2.m_mat[0x0][0x1], mat1.m_mat[0x0][0x2] + mat2.m_mat[0x0][0x2], mat1.m_mat[0x0][0x3] + mat2.m_mat[0x0][0x3],
				  		   		 mat1.m_mat[0x1][0x0] + mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] + mat2.m_mat[0x1][0x1], mat1.m_mat[0x1][0x2] + mat2.m_mat[0x1][0x2], mat1.m_mat[0x1][0x3] + mat2.m_mat[0x1][0x3],
				  		   		 mat1.m_mat[0x2][0x0] + mat2.m_mat[0x2][0x0], mat1.m_mat[0x2][0x1] + mat2.m_mat[0x2][0x1], mat1.m_mat[0x2][0x2] + mat2.m_mat[0x2][0x2], mat1.m_mat[0x2][0x3] + mat2.m_mat[0x2][0x3],
				  		   		 mat1.m_mat[0x3][0x0] + mat2.m_mat[0x3][0x0], mat1.m_mat[0x3][0x1] + mat2.m_mat[0x3][0x1], mat1.m_mat[0x3][0x2] + mat2.m_mat[0x3][0x2], mat1.m_mat[0x3][0x3] + mat2.m_mat[0x3][0x3] );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator*(const FF::Matrix4x4<T>& __FF_IN mat1, const FF::Matrix4x4<T>& __FF_IN mat2){
		return FF::Matrix4x4<T>( mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x0],
							     mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x1],
							     mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x2],
							     mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x3] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x3] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x3],

							     mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x0],
							     mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x1],
							     mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x2],
							     mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x3] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x3] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x3],

							     mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x0],
							     mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x1],
							     mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x2],
							     mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x3] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x3] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x3],

							     mat1.m_mat[0x3][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x3][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x3][0x2] * mat2.m_mat[0x2][0x0],
							     mat1.m_mat[0x3][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x3][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x3][0x2] * mat2.m_mat[0x2][0x1],
							     mat1.m_mat[0x3][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x3][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x3][0x2] * mat2.m_mat[0x2][0x2],
							     mat1.m_mat[0x3][0x0] * mat2.m_mat[0x0][0x3] + mat1.m_mat[0x3][0x1] * mat2.m_mat[0x1][0x3] + mat1.m_mat[0x3][0x2] * mat2.m_mat[0x2][0x3] );
	}

	template<typename T>
	inline FF::Vector4<T>   operator*(const FF::Matrix4x4<T>& __FF_IN mat,  const FF::Vector4<T>& __FF_IN vec){
		return FF::Vector4<T>( mat.m_mat[0x0][0x0] * vec.getXComponent(vec) + mat.m_mat[0x0][0x1] * vec.getYComponent(vec) + mat.m_mat[0x0][0x2] * vec.getZComponent(vec) + mat.m_mat[0x0][0x3] * vec.getWComponent(vec),
							   mat.m_mat[0x1][0x0] * vec.getXComponent(vec) + mat.m_mat[0x1][0x1] * vec.getYComponent(vec) + mat.m_mat[0x1][0x2] * vec.getZComponent(vec) + mat.m_mat[0x1][0x3] * vec.getWComponent(vec),
							   mat.m_mat[0x2][0x0] * vec.getXComponent(vec) + mat.m_mat[0x2][0x1] * vec.getYComponent(vec) + mat.m_mat[0x2][0x2] * vec.getZComponent(vec) + mat.m_mat[0x2][0x3] * vec.getWComponent(vec),
							   mat.m_mat[0x3][0x0] * vec.getXComponent(vec) + mat.m_mat[0x3][0x1] * vec.getYComponent(vec) + mat.m_mat[0x3][0x2] * vec.getZComponent(vec) + mat.m_mat[0x3][0x3] * vec.getWComponent(vec) );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator-(const FF::Matrix4x4<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix4x4<T>( mat.m_mat[0x0][0x0] - scalar, mat.m_mat[0x0][0x1] - scalar, mat.m_mat[0x0][0x2] - scalar, mat.m_mat[0x0][0x3] - scalar,
				  		   		 mat.m_mat[0x1][0x0] - scalar, mat.m_mat[0x1][0x1] - scalar, mat.m_mat[0x1][0x2] - scalar, mat.m_mat[0x1][0x3] - scalar,
				  		   		 mat.m_mat[0x2][0x0] - scalar, mat.m_mat[0x2][0x1] - scalar, mat.m_mat[0x2][0x2] - scalar, mat.m_mat[0x2][0x3] - scalar,
				  		   		 mat.m_mat[0x3][0x0] - scalar, mat.m_mat[0x3][0x1] - scalar, mat.m_mat[0x3][0x2] - scalar, mat.m_mat[0x3][0x3] - scalar );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator+(const FF::Matrix4x4<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix4x4<T>( mat.m_mat[0x0][0x0] + scalar, mat.m_mat[0x0][0x1] + scalar, mat.m_mat[0x0][0x2] + scalar, mat.m_mat[0x0][0x3] + scalar,
				  		   		 mat.m_mat[0x1][0x0] + scalar, mat.m_mat[0x1][0x1] + scalar, mat.m_mat[0x1][0x2] + scalar, mat.m_mat[0x1][0x3] + scalar,
				  		   		 mat.m_mat[0x2][0x0] + scalar, mat.m_mat[0x2][0x1] + scalar, mat.m_mat[0x2][0x2] + scalar, mat.m_mat[0x2][0x3] + scalar,
				  		   		 mat.m_mat[0x3][0x0] + scalar, mat.m_mat[0x3][0x1] + scalar, mat.m_mat[0x3][0x2] + scalar, mat.m_mat[0x3][0x3] + scalar );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator*(const FF::Matrix4x4<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix4x4<T>( mat.m_mat[0x0][0x0] * scalar, mat.m_mat[0x0][0x1] * scalar, mat.m_mat[0x0][0x2] * scalar, mat.m_mat[0x0][0x3] * scalar,
				  		   		 mat.m_mat[0x1][0x0] * scalar, mat.m_mat[0x1][0x1] * scalar, mat.m_mat[0x1][0x2] * scalar, mat.m_mat[0x1][0x3] * scalar,
				  		   		 mat.m_mat[0x2][0x0] * scalar, mat.m_mat[0x2][0x1] * scalar, mat.m_mat[0x2][0x2] * scalar, mat.m_mat[0x2][0x3] * scalar,
				  		   		 mat.m_mat[0x3][0x0] * scalar, mat.m_mat[0x3][0x1] * scalar, mat.m_mat[0x3][0x2] * scalar, mat.m_mat[0x3][0x3] * scalar );
	}

	template<typename T>
	inline FF::Matrix4x4<T> operator/(const FF::Matrix4x4<T>& __FF_IN mat,  const T& __FF_IN scalar){
		T divCoeff = 0x1 / scalar;
		return FF::Matrix4x4<T>( mat.m_mat[0x0][0x0] * divCoeff, mat.m_mat[0x0][0x1] * divCoeff, mat.m_mat[0x0][0x2] * divCoeff, mat.m_mat[0x0][0x3] * divCoeff,
				  		   		 mat.m_mat[0x1][0x0] * divCoeff, mat.m_mat[0x1][0x1] * divCoeff, mat.m_mat[0x1][0x2] * divCoeff, mat.m_mat[0x1][0x3] * divCoeff,
				  		   		 mat.m_mat[0x2][0x0] * divCoeff, mat.m_mat[0x2][0x1] * divCoeff, mat.m_mat[0x2][0x2] * divCoeff, mat.m_mat[0x2][0x3] * divCoeff,
				  		   		 mat.m_mat[0x3][0x0] * divCoeff, mat.m_mat[0x3][0x1] * divCoeff, mat.m_mat[0x3][0x2] * divCoeff, mat.m_mat[0x3][0x3] * divCoeff );
	}

	template<typename T>
	inline FF::Vector4<T> FF::Matrix4x4<T>::operator[](const std::size_t& __FF_IN rowNumber){
		assert(rowNumber < 0x4uL && "Going beyond the vector!");
		return FF::Vector4<T>(m_mat[rowNumber][0x0], m_mat[rowNumber][0x1], m_mat[rowNumber][0x2], m_mat[rowNumber][0x3]);
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, const FF::Matrix4x4<T>& m){
		std::cout << m.m_mat[0x0][0x0] << " | " << m.m_mat[0x0][0x1] << " | " << m.m_mat[0x0][0x2] << " | " << m.m_mat[0x0][0x3] << std::endl;
		std::cout << m.m_mat[0x1][0x0] << " | " << m.m_mat[0x1][0x1] << " | " << m.m_mat[0x1][0x2] << " | " << m.m_mat[0x1][0x3] << std::endl;
		std::cout << m.m_mat[0x2][0x0] << " | " << m.m_mat[0x2][0x1] << " | " << m.m_mat[0x2][0x2] << " | " << m.m_mat[0x2][0x3] << std::endl;
		std::cout << m.m_mat[0x3][0x0] << " | " << m.m_mat[0x3][0x1] << " | " << m.m_mat[0x3][0x2] << " | " << m.m_mat[0x3][0x3] << std::endl;

		return out;
	}
};

#endif // FF_MATRIX4X4_HXX_