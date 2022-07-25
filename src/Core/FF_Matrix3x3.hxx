#include "FF_Macros.hxx"
#include "FF_Vector3.hxx"

#ifndef FF_MATRIX3X3_HXX_
#define FF_MATRIX3X3_HXX_

namespace FF {
	/**
	 * @brief [Class that represent three-dimensional matrix]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Matrix3x3 {
	private:
		T m_mat[0x3][0x3];
	public:
		/**
		 * @brief [Default constructor are not defined to all entities in FF]
		 */
		explicit Matrix3x3(void) = delete;

		/**
		 * @brief [Constuctor with the parameters that have init MAT3 with scalar values]
		 * 
		 * @param v11 [Value with index (0,0)]
		 * @param v12 [Value with index (0,1)]
		 * @param v13 [Value with index (0,2)]
		 * @param v21 [Value with index (1,0)]
		 * @param v22 [Value with index (1,1)]
		 * @param v23 [Value with index (1,2)]
		 * @param v31 [Value with index (2,0)]
		 * @param v32 [Value with index (2,1)]
		 * @param v33 [Value with index (2,2)]
		 */
		explicit Matrix3x3(	T __FF_IN v11 = static_cast<T>(0.0f), T __FF_IN v12 = static_cast<T>(0.0f), T __FF_IN v13 = static_cast<T>(0.0f),
							T __FF_IN v21 = static_cast<T>(0.0f), T __FF_IN v22 = static_cast<T>(0.0f), T __FF_IN v23 = static_cast<T>(0.0f),
							T __FF_IN v31 = static_cast<T>(0.0f), T __FF_IN v32 = static_cast<T>(0.0f), T __FF_IN v33 = static_cast<T>(0.0f) )
		: m_mat{ v11, v12, v13,
		 		 v21, v22, v23,
		 		 v31, v32, v33 } {}

		/**
		 * @brief [Constuctor with the parameters that have init MAT3 with vectors]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @param vec3 [Third vector]
		 */
		explicit Matrix3x3( FF::Vector3<T>& __FF_IN vec1,
							FF::Vector3<T>& __FF_IN vec2,
							FF::Vector3<T>& __FF_IN vec3 );

		/**
		 * @brief [Friend function that instance identity matrix]
		 * @details [ [1 0 0],
		 * 			  [0 1 0],
		 * 			  [0 0 1] ]
		 * @return [Return identity matrix]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U>& Identity(void);

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
		inline void operator-=(const FF::Matrix3x3<T>& __FF_IN mat);

		/**
		 * @brief [Operator that calculate sum with this matrix and parameter matrix]
		 * @details [-]
		 * 
		 * @param vec [Matrix]
		 */
		inline void operator+=(const FF::Matrix3x3<T>& __FF_IN mat);


		/**
		 * @brief [Friend function that return -mat]
		 * @details [Apply '-' to each component]
		 * 
		 * @param mat [Matrix]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent origin matrix with other sign]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat);

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
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);

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
		friend inline FF::Matrix3x3<U> operator+(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);

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
		friend inline FF::Matrix3x3<U> operator*(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);


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
		friend inline FF::Vector3<U>   operator*(const FF::Matrix3x3<U>& __FF_IN mat,  const FF::Vector3<U>& __FF_IN vec);


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
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate sum of matrix and scalar]
		 * @details [Each component is sum of appropriate components origin vectors]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent sum of origin vectors]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator+(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate composition mat and scalar value]
		 * @details [Each component mul to scalar]
		 * 
		 * @param mat [Vector]
		 * @tparam U [Generic type]
		 * @return [Return matrix that represent mul of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator*(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate division matrix and scalar value]
		 * @details [Each component divide to scalar]
		 * 
		 * @param mat [Matrix]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent div of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator/(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		
		/**
		 * @brief [Method that calculate determinant of matrix]
		 * 
		 * @return [Return determinant]
		 */
		inline T&& 	      Determinant(void) const;

		/**
		 * @brief [Friend function that calculate determinant of matrix]
		 * 
		 * @return [Return determinant]
		 */
		template<typename U>
		friend inline U&& Determinant(const FF::Matrix3x3<U>& __FF_IN mat);


		/**
		 * @brief [Method that return row of matrix such a vector]
		 * @details [-]
		 * 
		 * @param index [Index of row]
		 * @return [Return vector]
		 */
		inline FF::Vector3<T>  operator[](const std::size_t& __FF_IN rowNumber);

		/**
		 * @brief [Method that return element by indexes]
		 * @details [Const method]
		 * 
		 * @param i [Index of row]
		 * @param j [Index of column]
		 * @return [Return element]
		 */
		inline const T&        operator()(const std::size_t& __FF_IN i, const std::size_t& __FF_IN j) const;

		
		/**
		 * @brief [Debug override << operator]
		 * @details [Used for output values in ostream. Friend function]
		 * 
		 * @param out [Out stream]
		 * @param m [Matrix]
		 */
		template<typename U>
		friend inline std::ostream& operator<<(std::ostream& __FF_OUT out, const FF::Matrix3x3<U>& __FF_IN m);

		/**
		 * @brief [Default destructor]
		 * @details [-]
		 */
		~Matrix3x3(void) = default;
	};

	template<typename T>
	FF::Matrix3x3<T>::Matrix3x3( FF::Vector3<T>& __FF_IN vec1,
						 	     FF::Vector3<T>& __FF_IN vec2,
						 	     FF::Vector3<T>& __FF_IN vec3 )
	: m_mat{ vec1.getXComponent(), vec1.getYComponent(), vec1.GetZComponent(),
		 	 vec2.getXComponent(), vec2.getYComponent(), vec2.GetZComponent(),
		 	 vec3.getXComponent(), vec3.getYComponent(), vec3.GetZComponent() } {}

	template<typename T>
	inline FF::Matrix3x3<T>& Identity(void){
		return FF::Matrix3x3<T>( static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
				  		  	     static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
				  		   		 static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f) );
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator-=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] -= scalar; this->m_mat[0x0][0x1] -= scalar; this->m_mat[0x0][0x2] -= scalar;
		this->m_mat[0x1][0x0] -= scalar; this->m_mat[0x1][0x1] -= scalar; this->m_mat[0x1][0x2] -= scalar;
		this->m_mat[0x2][0x0] -= scalar; this->m_mat[0x2][0x1] -= scalar; this->m_mat[0x2][0x2] -= scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator+=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] += scalar; this->m_mat[0x0][0x1] += scalar; this->m_mat[0x0][0x2] += scalar;
		this->m_mat[0x1][0x0] += scalar; this->m_mat[0x1][0x1] += scalar; this->m_mat[0x1][0x2] += scalar;
		this->m_mat[0x2][0x0] += scalar; this->m_mat[0x2][0x1] += scalar; this->m_mat[0x2][0x2] += scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator*=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] *= scalar; this->m_mat[0x0][0x1] *= scalar; this->m_mat[0x0][0x2] *= scalar;
		this->m_mat[0x1][0x0] *= scalar; this->m_mat[0x1][0x1] *= scalar; this->m_mat[0x1][0x2] *= scalar;
		this->m_mat[0x2][0x0] *= scalar; this->m_mat[0x2][0x1] *= scalar; this->m_mat[0x2][0x2] *= scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator-=(const FF::Matrix3x3<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] -= mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] -= mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] -= mat.m_mat[0x0][0x2];
		this->m_mat[0x1][0x0] -= mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] -= mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] -= mat.m_mat[0x1][0x2];
		this->m_mat[0x2][0x0] -= mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] -= mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] -= mat.m_mat[0x2][0x2];
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator+=(const FF::Matrix3x3<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] += mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] += mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] += mat.m_mat[0x0][0x2];
		this->m_mat[0x1][0x0] += mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] += mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] += mat.m_mat[0x1][0x2];
		this->m_mat[0x2][0x0] += mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] += mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] += mat.m_mat[0x2][0x2];
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator/=(const T& __FF_IN scalar){
		T divCoeff = 0x1 / scalar;
		this->m_mat[0x0][0x0] *= divCoeff; this->m_mat[0x0][0x1] *= divCoeff; this->m_mat[0x0][0x2] *= divCoeff;
		this->m_mat[0x1][0x0] *= divCoeff; this->m_mat[0x1][0x1] *= divCoeff; this->m_mat[0x1][0x2] *= divCoeff;
		this->m_mat[0x2][0x0] *= divCoeff; this->m_mat[0x2][0x1] *= divCoeff; this->m_mat[0x2][0x2] *= divCoeff;
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator-(const FF::Matrix3x3<T>& __FF_IN mat){
		return FF::Matrix3x3<T>( -mat.m_mat[0x0][0x0], -mat.m_mat[0x0][0x1], -mat.m_mat[0x0][0x2],
				  		   		 -mat.m_mat[0x1][0x0], -mat.m_mat[0x1][0x1], -mat.m_mat[0x1][0x2], 
				  		   		 -mat.m_mat[0x2][0x0], -mat.m_mat[0x2][0x1], -mat.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator-(const FF::Matrix3x3<T>& __FF_IN mat1, const FF::Matrix3x3<T>& __FF_IN mat2){
		return FF::Matrix3x3<T>( mat1.m_mat[0x0][0x0] - mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] - mat2.m_mat[0x0][0x1], mat1.m_mat[0x0][0x2] - mat2.m_mat[0x0][0x2],
				  		   		 mat1.m_mat[0x1][0x0] - mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] - mat2.m_mat[0x1][0x1], mat1.m_mat[0x1][0x2] - mat2.m_mat[0x1][0x2],
				  		   		 mat1.m_mat[0x2][0x0] - mat2.m_mat[0x2][0x0], mat1.m_mat[0x2][0x1] - mat2.m_mat[0x2][0x1], mat1.m_mat[0x2][0x2] - mat2.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator+(const FF::Matrix3x3<T>& __FF_IN mat1, const FF::Matrix3x3<T>& __FF_IN mat2){
		return FF::Matrix3x3<T>( mat1.m_mat[0x0][0x0] + mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] + mat2.m_mat[0x0][0x1], mat1.m_mat[0x0][0x2] + mat2.m_mat[0x0][0x2],
				  		   		 mat1.m_mat[0x1][0x0] + mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] + mat2.m_mat[0x1][0x1], mat1.m_mat[0x1][0x2] + mat2.m_mat[0x1][0x2],
				  		   		 mat1.m_mat[0x2][0x0] + mat2.m_mat[0x2][0x0], mat1.m_mat[0x2][0x1] + mat2.m_mat[0x2][0x1], mat1.m_mat[0x2][0x2] + mat2.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator*(const FF::Matrix3x3<T>& __FF_IN mat1, const FF::Matrix3x3<T>& __FF_IN mat2){
		return FF::Matrix3x3<T>( mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x0],
						  		 mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x1],
						  		 mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x2],

						  		 mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x0],
						  		 mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x1],
						  		 mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x2],

						  		 mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x0],
						  		 mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x1],
						  		 mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Vector3<T>   operator*(const FF::Matrix3x3<T>& __FF_IN mat,  const FF::Vector3<T>& __FF_IN vec){
		return FF::Vector3<T>( mat.m_mat[0x0][0x0] * getXComponent(vec) + mat.m_mat[0x0][0x1] * getYComponent(vec) + mat.m_mat[0x0][0x2] * getZComponent(vec),
						  	   mat.m_mat[0x1][0x0] * getXComponent(vec) + mat.m_mat[0x1][0x1] * getYComponent(vec) + mat.m_mat[0x1][0x2] * getZComponent(vec),
						  	   mat.m_mat[0x2][0x0] * getXComponent(vec) + mat.m_mat[0x2][0x1] * getYComponent(vec) + mat.m_mat[0x2][0x2] * getZComponent(vec) );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator-(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] - scalar, mat.m_mat[0x0][0x1] - scalar, mat.m_mat[0x0][0x2] - scalar,
				  		   		 mat.m_mat[0x1][0x0] - scalar, mat.m_mat[0x1][0x1] - scalar, mat.m_mat[0x1][0x2] - scalar,
				  		   		 mat.m_mat[0x2][0x0] - scalar, mat.m_mat[0x2][0x1] - scalar, mat.m_mat[0x2][0x2] - scalar );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator+(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] + scalar, mat.m_mat[0x0][0x1] + scalar, mat.m_mat[0x0][0x2] + scalar,
				  		   		 mat.m_mat[0x1][0x0] + scalar, mat.m_mat[0x1][0x1] + scalar, mat.m_mat[0x1][0x2] + scalar,
				  		   		 mat.m_mat[0x2][0x0] + scalar, mat.m_mat[0x2][0x1] + scalar, mat.m_mat[0x2][0x2] + scalar );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator*(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] * scalar, mat.m_mat[0x0][0x1] * scalar, mat.m_mat[0x0][0x2] * scalar,
				  		   		 mat.m_mat[0x1][0x0] * scalar, mat.m_mat[0x1][0x1] * scalar, mat.m_mat[0x1][0x2] * scalar,
				  		   		 mat.m_mat[0x2][0x0] * scalar, mat.m_mat[0x2][0x1] * scalar, mat.m_mat[0x2][0x2] * scalar );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator/(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		T divCoeff = 0x1 / scalar;
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] * divCoeff, mat.m_mat[0x0][0x1] * divCoeff, mat.m_mat[0x0][0x2] * divCoeff,
				  		   		 mat.m_mat[0x1][0x0] * divCoeff, mat.m_mat[0x1][0x1] * divCoeff, mat.m_mat[0x1][0x2] * divCoeff,
				  		   		 mat.m_mat[0x2][0x0] * divCoeff, mat.m_mat[0x2][0x1] * divCoeff, mat.m_mat[0x2][0x2] * divCoeff );
	}

	template<typename T>
	inline T&& FF::Matrix3x3<T>::Determinant(void) const {
		return (  this->m_mat[0x0][0x0] * (this->m_mat[0x1][0x1] * this->m_mat[0x2][0x2] - this->m_mat[0x1][0x2] * this->m_mat[0x2][0x1])
				- this->m_mat[0x0][0x1] * (this->m_mat[0x1][0x0] * this->m_mat[0x2][0x2] - this->m_mat[0x1][0x2] * this->m_mat[0x2][0x0])
				+ this->m_mat[0x0][0x2] * (this->m_mat[0x1][0x0] * this->m_mat[0x2][0x1] - this->m_mat[0x1][0x1] * this->m_mat[0x2][0x0]) );
	}

	template<typename T>
	inline T&& Determinant(const FF::Matrix3x3<T>& __FF_IN mat){
		return (  mat.m_mat[0x0][0x0] * (mat.m_mat[0x1][0x1] * mat.m_mat[0x2][0x2] - mat.m_mat[0x1][0x2] * mat.m_mat[0x2][0x1])
				- mat.m_mat[0x0][0x1] * (mat.m_mat[0x1][0x0] * mat.m_mat[0x2][0x2] - mat.m_mat[0x1][0x2] * mat.m_mat[0x2][0x0])
				+ mat.m_mat[0x0][0x2] * (mat.m_mat[0x1][0x0] * mat.m_mat[0x2][0x1] - mat.m_mat[0x1][0x1] * mat.m_mat[0x2][0x0]) );
	}

	template<typename T>
	inline FF::Vector3<T> FF::Matrix3x3<T>::operator[](const std::size_t& __FF_IN rowNumber){
		assert(rowNumber < 0x3uL && "Going beyond the vector!");
		return FF::Vector3<T>(this->m_mat[rowNumber][0x0], this->m_mat[rowNumber][0x1], this->m_mat[rowNumber][0x2]);
	}

	template<typename T>
	inline const T& FF::Matrix3x3<T>::operator()(const std::size_t& i, const std::size_t& j) const {
		return this->m_mat[i][j];
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, const FF::Matrix3x3<T>& m){
		std::cout << m.m_mat[0x0][0x0] << " | " << m.m_mat[0x0][0x1] << " | " << m.m_mat[0x0][0x2] << std::endl;
		std::cout << m.m_mat[0x1][0x0] << " | " << m.m_mat[0x1][0x1] << " | " << m.m_mat[0x1][0x2] << std::endl;
		std::cout << m.m_mat[0x2][0x0] << " | " << m.m_mat[0x2][0x1] << " | " << m.m_mat[0x2][0x2] << std::endl;

		return out;
	}
};

#endif // FF_MATRIX3X3_HXX_