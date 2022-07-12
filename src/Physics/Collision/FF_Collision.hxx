#include "..\..\Core\FF_CommonMath.hxx"

#include "..\..\Core\FF_Vector3.hxx"

#include "FF_AABB.hxx"
#include "FF_BoundedSphere.hxx"

#ifndef FF_COLLISION_HXX_
#define FF_COLLISION_HXX_

namespace FF {
	template<typename T>
	class Collision {
	public:
		explicit Collision(void) = default;

		inline const bool AABBIntersectAABB(FF::AABB<T>& __FF_IN first, FF::AABB<T>& __FF_IN second) const;
		inline const bool BSphereIntersectBSphere(FF::BoundedSphere<T>& __FF_IN first, FF::BoundedSphere<T>& __FF_IN second) const;

		// inline const bool CheckCollision(const MaterialPoint<T>& firstObject, const MaterialPoint<T>& secondObject, const bool (*ReactionFunc)(void)) const;

		~Collision(void) = default;	
	};

	/**
	 * @brief [Simple checking to intersect AABB]
	 * @details [Method check each component of two AABB by two base point]
	 * 
	 * @param first [First AABB]
	 * @param second [Second AABB]
	 * @return [Return true if AABB intersected and false in another case]
	 */
	template<typename T>
	inline const bool AABBIntersectAABB(FF::AABB<T>& first, FF::AABB<T>& second) const {
		if (first.GetTopBound().GetXComponent() < second.GetBottomBound().GetXComponent() ||
				second.GetTopBound().GetXComponent() < first.GetBottomBound().GetXComponent()) {
			return false;
		}
		
		if (first.GetTopBound().GetYComponent() < second.GetBottomBound().GetYComponent() ||
				second.GetTopBound().GetYComponent() < first.GetBottomBound().GetYComponent()) {
			return false;
		}

		if (first.GetTopBound().GetZComponent() < second.GetBottomBound().GetZComponent() ||
				second.GetTopBound().GetZComponent() < first.GetBottomBound().GetZComponent()) {
			return false;
		}

		return true;
	}

	/**
	 * @brief [Method check the intersection of two BoundedSphere]
	 * @details [-]
	 * 
	 * @param first [First vector]
	 * @param second [Second vector]
	 * @tparam T [Generic type]
	 * @return [Return true if spheres intersected, and false in another case]
	 */
	template<typename T>
	inline const bool BSphereIntersectBSphere(FF::BoundedSphere<T>& __FF_IN first, FF::BoundedSphere<T>& __FF_IN second) const {
		T sumRadius = first.GetRadius() + second.GetRadius();
		return (FF::sqr(sumRadius) > FF::SquaredDistance(first, second));
	}

	/*template<typename T>
	inline const bool CheckCollision(const MaterialPoint<T>& firstObject, const MaterialPoint<T>& secondObject, const bool (*ReactionFunc)(void)) const {
		FF::Vector3<T> distance = firstObjectPosition.GetLocation() - firstObjectPosition.GetLocation();
		T minDistance = sqr(firstObjectPosition.GetBoundedSphereRadius() + secondObject.GetBoundedSphereRadius());

		if (distance.SquaredMagnitude() < minDistance) {
			ReactionFunc();
		}
	}*/
};

#endif // FF_COLLISION_HXX_