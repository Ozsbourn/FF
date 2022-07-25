#include <cmath>
#include <iostream>
 
#include "FF_Macros.hxx"
#include "FF_CommonMath.hxx"

#ifndef FF_VECTOR3_HXX_
#define FF_VECTOR3_HXX_

namespace FF {
    /**
     * @brief [Class that represent three-dimensional vector]
     * @details [Three-dimensional vector have a two components, that describe X, Y and Z components,
     *            and is used to describe something in 3D spaces]
     * 
     * @tparam T [Generic type]
     */
    template<typename T>
    class Vector3 {
    private:
        T m_x;
        T m_y;
        T m_z;
    public:
        /**
         * @brief [Default constructor are not defined to all entities in FF]
         */
        explicit Vector3(void) = delete;


        /**
         * @brief [Constuctor with the parameters that have init VEC2 with scalar values for components]
         * 
         * @param x [X component]
         * @param y [Y component]
         */
        explicit Vector3( T __FF_IN x = static_cast<T>(0.0f), 
                          T __FF_IN y = static_cast<T>(0.0f),
                          T __FF_IN z = static_cast<T>(0.0f) )
        : m_x(x), m_y(y), m_z(z) {};


        /**
         * @brief [Copy constructor to VEC3]
         * @details [Copy each component of VEC to this vector]
         * 
         * @param vec [Vector]
         */
        explicit Vector3(FF::Vector3<T>& __FF_IN vec);


        /**
         * @brief [Method that set X component of vector]
         * 
         * @param x [Value of X component]
         */
        inline void SetXComponent(T __FF_IN x);
        
        /**
         * @brief [Method that set Y component of vector]
         * 
         * @param x [Value of Y component]
         */
        inline void SetYComponent(T __FF_IN y);
        
        /**
         * @brief [Method that set Z component of vector]
         * 
         * @param x [Value of Z component]
         */
        inline void SetZComponent(T __FF_IN z);


        /**
         * @brief [Method that get X component of vector]
         * @details [Const method]
         * 
         * @param y [Value of X component]
         */
        const inline T& GetXComponent(void) const;
        
        /**
         * @brief [Method that get Z component of vector]
         * @details [Const method]
         * 
         * @param y [Value of Z component]
         */
        const inline T& GetYComponent(void) const;
        
        /**
         * @brief [Method that get Y component of vector]
         * @details [Const method]
         * 
         * @param y [Value of Y component]
         */
        const inline T& GetZComponent(void) const;


        /**
         * @brief [Friend function that return -vec]
         * @details [Apply '-' to each component]
         * 
         * @param vec [Vector]
         * @tparam U [Generic type]
         * @return [Return vector that represent origin vector with other sign]
         */
        template<typename U>
        friend Vector3<U> operator-(const FF::Vector3<U>& __FF_IN vec);

        /**
         * @brief [Friend function that calculate difference of two vecs]
         * @details [Each component is difference of appropriate components of parameter vectors]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam U [Generic type]
         * @return [Return vectors that represent difference of two vectors]
         */
        template<typename U>
        friend Vector3<U> operator-(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);

        /**
         * @brief [Friend function that calculate sum of two vector]
         * @details [Each component is sum of appropriate components origin vectors]
         * 
         * @param vec [Vector]
         * @tparam U [Generic type]
         * @return [Return vector that represent sum of origin vectors]
         */
        template<typename U>
        friend Vector3<U> operator+(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);

        /**
         * @brief [Friend function that calculate composition vec and scalar value]
         * @details [Each component mul to scalar]
         * 
         * @param vec [Vector]
         * @tparam U [Generic type]
         * @return [Return vector that represent mul of origin vector and scalar value]
         */
        template<typename U>
        friend Vector3<U> operator*(const FF::Vector3<U>& __FF_IN vec,  const U& __FF_IN scalar);

        /**
         * @brief [Friend function that calculate division vector and scalar value]
         * @details [Each component divide to scalar]
         * 
         * @param vec [Vector]
         * @tparam U [Generic type]
         * @return [Return vector that represent div of origin vector and scalar value]
         */
        template<typename U>
        friend Vector3<U> operator/(const FF::Vector3<U>& __FF_IN vec,  const U& __FF_IN scalar);

        
        /**
         * @brief [Operator that calculate difference of this vector and scalar]
         * @details [-]
         * 
         * @param scalar [Scalar value]
         */
        inline void operator-=(const T& __FF_IN scalar);

        /**
         * @brief [Operator that calculate sum of this vector and scalar]
         * @details [-]
         * 
         * @param scalar [Scalar value]
         */
        inline void operator+=(const T& __FF_IN scalar);

        /**
         * @brief [Operator that calculate mul of this vector and scalar]
         * @details [-]
         * 
         * @param scalar [Scalar value]
         */
        inline void operator*=(const T& __FF_IN scalar);

        /**
         * @brief [Operator that calculate div of this vector and scalar]
         * @details [-]
         * 
         * @param scalar [Scalar value]
         */
        inline void operator/=(const T& __FF_IN scalar);

        /**
         * @brief [Operator that calculate dif with this vector and parameter vector]
         * @details [-]
         * 
         * @param vec [Vector]
         */
        inline void operator-=(const FF::Vector3<T>& __FF_IN vec);
        /**
         * @brief [Operator that calculate sum with this vector and parameter vector]
         * @details [-]
         * 
         * @param vec [Vector]
         */
        inline void operator+=(const FF::Vector3<T>& __FF_IN vec);


        /**
            * @brief [Method that return component of vector such as lvalue]
            * @details [-]
            * 
            * @param index [Index of component vector]
            * @return [Return component like a lvalue]
            */
        const T& operator[](std::size_t __FF_IN index);


        /**
         * @brief [Friend function that calculate dot product of two vectors]
         * @details [Dot product is sum of all mul appropriate components]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam U [Generic type]
         * @return [Return value that represent result of dot product]
         */
        template<typename U>
        friend inline U               DotProduct(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);

        /**
         * @brief [Friend function that calculate cross product of two vectors]
         * @details [Cross product for 3D vecs is 3D vec with components (first.y * second.z - first.z * second.y; 
         *                                                                  - first.x * second.z + first.z * second.x;
         *                                                                      first.x * second.y - first.y * second.x)]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam U [Generic type]
         * @return [Return value that represent result of cross product]
         */
        template<typename U>
        friend inline FF::Vector3<U>& CrossProduct(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);

        
        /**
         * @brief [Method that find project vector VEC1 on vector VEC2]
         * @details [Method calculate vector project VEC1 on VEC2]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam T [Generic type]
         * @return [Return the project of vector]
         */
        template<typename U>
        friend inline FF::Vector3<U>& Project(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);
        
        /**
         * @brief [Method that find reject vectors VEC1 and VEC2]
         * @details [Method calculate reject vector VEC1 from VEC2]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam T [Generic type]
         * @return [Return reject of vectors]
         */
        template<typename U>
        friend inline FF::Vector3<U>& Reject(const FF::Vector3<U>& __FF_IN vec1,  const FF::Vector3<U>& __FF_IN vec2);

        /**
         * @brief [Friend function that calculate distance detween two vectors]
         * @details [Distance is sqrt((x1 - x2)^2 + (y1 - y2)^2 + (z1 - z2)^2)]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam U [Generic type]
         * @return [Return distance between two vectors]
         */
        template<typename U>
        friend inline U               Distance(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);

        /**
         * @brief [Friend function that calculate squared distance detween two vectors]
         * @details [Squared distance is (x1 - x2)^2 + (y1 - y2)^2 + (z1 - z2)^2]
         * 
         * @param vec1 [First vector]
         * @param vec2 [Second vector]
         * @tparam U [Generic type]
         * @return [Return squared distance between two vectors]
         */
        template<typename U>
        friend inline U               SquaredDistance(const FF::Vector3<U>& __FF_IN vec1, const FF::Vector3<U>& __FF_IN vec2);
        
        /**
         * @brief [Method that calculate magnitude of vector]
         * @details [Method find and return square root of sum of squares of each component of vector]
         * 
         * @param vec [Vector]
         * @tparam T [Generic type]
         * @return [Return the magnitude of vector]
         */
        template<typename U>
        friend inline U               Magnitude(const FF::Vector3<U>& __FF_IN vec);
       
        /**
         * @brief [Method that find square of magnitude of vector]
         * @details [Method find and return sum of squares of each component of vector]
         * 
         * @param vec [Vector]
         * @tparam T [Generic type]
         * @return [Return sqaured magnitude of vector]
         */
        template<typename U>
        friend inline U               SquaredMagnitude(const FF::Vector3<U>& __FF_IN vec);
        
        /**
         * @brief [Method that that instance the origin vector after normalize]
         * @details [Method normalize a vector: subdivide each component on magnitude of this vector]
         * 
         * @param vec [Vector]
         * @tparam T [Generic type]
         * @return [Return the copy of origin vector that was normalize]
         */
        template<typename U>
        friend inline FF::Vector3<U>& Normalize(const FF::Vector3<U>& __FF_IN vec);


        /**
         * @brief [Default destructor]
         */
        ~Vector3(void) = default;


        /**
         * @brief [Debug override << operator]
         * @details [Used for output values in ostream. Friend function]
         * 
         * @param out [Out stream]
         * @param vec [Vector]
         */
        template<typename U>
        friend inline std::ostream& operator<< (std::ostream& __FF_IN out, FF::Vector3<U>& __FF_IN vec);
    };

    template<typename T>
    FF::Vector3<T>::Vector3(FF::Vector3<T>& __FF_IN vec) {
        this->m_x = vec.GetXComponent();
        this->m_y = vec.GetYComponent();
        this->m_z = vec.GetZComponent();
    }

    template<typename T>
    inline void FF::Vector3<T>::SetXComponent(T __FF_IN x) {
        this->m_x = x;
    }

    template<typename T>
    inline void FF::Vector3<T>::SetYComponent(T __FF_IN y) {
        this->m_y = y;
    }

    template<typename T>
    inline void FF::Vector3<T>::SetZComponent(T __FF_IN z) {
        this->m_z = z;
    }

    template<typename T>
    const inline T& FF::Vector3<T>::GetXComponent(void) const {
        return m_x;
    }

    template<typename T>
    const inline T& FF::Vector3<T>::GetYComponent(void) const {
        return m_y;
    }

    template<typename T>
    const inline T& FF::Vector3<T>::GetZComponent(void) const {
        return m_z;
    }

    template<typename T>
    FF::Vector3<T> operator-(const FF::Vector3<T>& __FF_IN vec){
        return FF::Vector3<T>( -vec.m_x,
                               -vec.m_y, 
                               -vec.m_z);
    }

    template<typename T>
    FF::Vector3<T> operator-(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return FF::Vector3<T>( vec1.m_x - vec2.m_x,
                               vec1.m_y - vec2.m_y,
                               vec1.m_z - vec2.m_z );
    }
        
    template<typename T>
    FF::Vector3<T> operator+(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return FF::Vector3<T>( vec1.m_x + vec2.m_x,
                               vec1.m_y + vec2.m_y,
                               vec1.m_z + vec2.m_z );
    }
        
    template<typename T>
    FF::Vector3<T> operator*(const FF::Vector3<T>& __FF_IN vec,  const T& __FF_IN scalar){
        return FF::Vector3<T>( vec.m_x * scalar,
                               vec.m_y * scalar,
                               vec.m_z * scalar );
    }
        
    template<typename T>
    FF::Vector3<T> operator/(const FF::Vector3<T>& __FF_IN vec,  const T& __FF_IN scalar){
        return FF::Vector3<T>( vec.m_x / scalar,
                               vec.m_y / scalar,
                               vec.m_z / scalar );
    }

    template<typename T>
    inline void FF::Vector3<T>::operator-=(const T& __FF_IN scalar){
        this->m_x -= scalar;
        this->m_y -= scalar;
        this->m_z -= scalar;
    }

    template<typename T>
    inline void FF::Vector3<T>::operator+=(const T& __FF_IN scalar){
        this->m_x += scalar;
        this->m_y += scalar;
        this->m_z += scalar;
    }

    template<typename T>
    inline void FF::Vector3<T>::operator*=(const T& __FF_IN scalar){
        this->m_x *= scalar;
        this->m_y *= scalar;
        this->m_y *= scalar;
    }

    template<typename T>
    inline void FF::Vector3<T>::operator/=(const T& __FF_IN scalar){
        this->m_x /= scalar;
        this->m_y /= scalar;
        this->m_y /= scalar;
    }

    template<typename T>
    inline void FF::Vector3<T>::operator-=(const FF::Vector3<T>& __FF_IN vec){
        this->m_x -= vec.GetXComponent();
        this->m_y -= vec.GetYComponent();
        this->m_z -= vec.GetZComponent();
    }

    template<typename T>
    inline void FF::Vector3<T>::operator+=(const FF::Vector3<T>& __FF_IN vec){
        this->m_x += vec.GetXComponent();
        this->m_y += vec.GetYComponent();
        this->m_z += vec.GetZComponent();
    }

    template<typename T>
    const T& FF::Vector3<T>::operator[](std::size_t __FF_IN index){
        FF_ASSERT_MESSAGE(index < 0x3uL, "Going beyond the vector");
        return *(&(this->m_x) + index);
    }

    template<typename T>
    inline T DotProduct(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y + vec1.m_z * vec2.m_z);
    }

    template<typename T>
    inline FF::Vector3<T>& CrossProduct(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return FF::Vector3<T>( vec1.GetYComponent() * vec2.GetZComponent() - vec1.GetZComponent() * vec2.GetYComponent(),
                               vec1.GetZComponent() * vec2.GetXComponent() - vec1.GetXComponent() * vec2.GetZComponent(),
                               vec1.GetXComponent() * vec2.GetYComponent() - vec1.GetYComponent() * vec2.GetXComponent() );
    }

    template<typename T>
    inline FF::Vector3<T>& Project(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return (vec2 * FF::DotProduct(vec1, vec2) / FF::DotProduct(vec2, vec2));
    }

    template<typename T>
    inline FF::Vector3<T>& Reject(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return (vec1 - vec2 * FF::DotProduct(vec1, vec2) / FF::DotProduct(vec2, vec2));
    }

    template<typename T>
    inline T Distance(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return sqrt( FF::sqr(vec1.GetXComponent() - vec2.GetXComponent()) +
                     FF::sqr(vec1.GetYComponent() - vec2.GetYComponent()) +
                     FF::sqr(vec1.GetZComponent() - vec2.GetZComponent()) );
    }

    template<typename T>
    inline T SquaredDistance(const FF::Vector3<T>& __FF_IN vec1, const FF::Vector3<T>& __FF_IN vec2){
        return ( FF::sqr(vec1.GetXComponent() - vec2.GetXComponent()) +
                 FF::sqr(vec1.GetYComponent() - vec2.GetYComponent()) +
                 FF::sqr(vec1.GetZComponent() - vec2.GetZComponent()) );
    }

    template<typename T>
    inline T Magnitude(const FF::Vector3<T>& __FF_IN vec){    
        return sqrt( FF::sqr(vec.m_x) + 
                     FF::sqr(vec.m_y) + 
                     FF::sqr(vec.m_z) );
    }

    template<typename T>
    inline T SquaredMagnitude(const Vector3<T>& __FF_IN vec){
        return ( FF::sqr(vec.m_x) + 
                 FF::sqr(vec.m_y) + 
                 FF::sqr(vec.m_z) );
    }

    template<typename T>
    inline FF::Vector3<T>& Normalize(const FF::Vector3<T>& __FF_IN vec){
        return (vec / Magnitude(vec));
    }

    template<typename T>
    std::ostream& operator<< (std::ostream& __FF_IN out, Vector3<T>& __FF_IN vec){
        std::cout << "{" << vec.m_x << ", " << vec.m_y << "," << vec.m_z << "}" << std::endl;
        return out;
    }
};

#endif // FF_VECTOR3_HXX_