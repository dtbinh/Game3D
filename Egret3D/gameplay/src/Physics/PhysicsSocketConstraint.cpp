#include "Base.h"
#include "PhysicsSocketConstraint.h"
#include "Node.h"

namespace egret
{

PhysicsSocketConstraint::PhysicsSocketConstraint(PhysicsRigidBody* a, PhysicsRigidBody* b)
    : PhysicsConstraint(a, b)
{
    GP_ASSERT(a && a->_body && a->getNode());
    if (b)
    {
        GP_ASSERT(b->_body && b->getNode());
        kmVec3 origin = centerOfMassMidpoint(a->getNode(), b->getNode());
        btTransform frameInA = getTransformOffset(a->getNode(), origin);
        btTransform frameInB = getTransformOffset(b->getNode(), origin);

        _constraint = bullet_new<btPoint2PointConstraint>(*a->_body, *b->_body, frameInA.getOrigin(), frameInB.getOrigin());
    }
    else
    {
        _constraint = bullet_new<btPoint2PointConstraint>(*a->_body, btVector3(0.0f, 0.0f, 0.0f));
    }
}

PhysicsSocketConstraint::PhysicsSocketConstraint(PhysicsRigidBody* a, const kmVec3& translationOffsetA, 
                                                 PhysicsRigidBody* b, const kmVec3& translationOffsetB)
    : PhysicsConstraint(a, b)
{
    GP_ASSERT(a && a->_body && a->getNode());

    // Take scale into account for the first node's translation offset.
    kmVec3 sA = vec3Zero;
    //a->getNode()->getWorldMatrix().getScale(&sA);
	kmMat4Decompose(&a->getNode()->getWorldMatrix(), &sA, NULL, NULL);
	kmVec3 tA = { translationOffsetA.x * sA.x, translationOffsetA.y * sA.y, translationOffsetA.z * sA.z };

    if (b)
    {
        GP_ASSERT(b->_body && b->getNode());

        // Take scale into account for the second node's translation offset.
        kmVec3 sB = vec3Zero;
        //b->getNode()->getWorldMatrix().getScale(&sB);
		kmMat4Decompose(&b->getNode()->getWorldMatrix(), &sB, NULL, NULL );
		kmVec3 tB = { translationOffsetB.x * sB.x, translationOffsetB.y * sB.y, translationOffsetB.z * sB.z };

        _constraint = bullet_new<btPoint2PointConstraint>(*a->_body, *b->_body, BV(tA), BV(tB));
    }
    else
    {
        _constraint = bullet_new<btPoint2PointConstraint>(*a->_body, BV(tA));
    }
}

PhysicsSocketConstraint::~PhysicsSocketConstraint()
{
    // Used
}

}
