/*
Copyright (c) 2008, Luke Benstead.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef QUATERNION_H_INCLUDED
#define QUATERNION_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "utility.h"

struct kmMat4;
struct kmMat3;
struct kmVec3;

typedef struct kmQuaternion {
    kmScalar x;
    kmScalar y;
    kmScalar z;
    kmScalar w;
} kmQuaternion;

kmQuaternion* kmQuaternionSet(kmQuaternion *pOut, float x, float y, float z, float w);

kmQuaternion* const kmQuaternionConjugate(kmQuaternion* pOut, const kmQuaternion* pIn);

const kmScalar     kmQuaternionDot(const kmQuaternion* q1, const kmQuaternion* q2); ///< Returns the dot product of the 2 quaternions

kmQuaternion* kmQuaternionExp(kmQuaternion* pOut, const kmQuaternion* pIn); ///< Returns the exponential of the quaternion

kmQuaternion* kmQuaternionIdentity(kmQuaternion* pOut);

///< Returns the inverse of the passed Quaternion

kmQuaternion* kmQuaternionInverse(kmQuaternion* pOut,
                                            const kmQuaternion* pIn);

///< Returns true if the quaternion is an identity quaternion

int  kmQuaternionIsIdentity(const kmQuaternion* pIn);

///< Returns the length of the quaternion

kmScalar kmQuaternionLength(const kmQuaternion* pIn);

///< Returns the length of the quaternion squared (prevents a sqrt)

kmScalar kmQuaternionLengthSq(const kmQuaternion* pIn);

///< Returns the natural logarithm

kmQuaternion* kmQuaternionLn(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Multiplies 2 quaternions together

kmQuaternion* kmQuaternionMultiply(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2);

///< Normalizes a quaternion

kmQuaternion* kmQuaternionNormalize(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Rotates a quaternion around an axis

kmQuaternion* kmQuaternionRotationAxis(kmQuaternion* pOut, const struct kmVec3* pV, kmScalar angle);

///< Creates a quaternion from a rotation matrix

kmQuaternion* kmQuaternionRotationMatrix(kmQuaternion* pOut, const struct kmMat3* pIn);

///< Create a quaternion from yaw, pitch and roll

kmQuaternion* kmQuaternionRotationYawPitchRoll(kmQuaternion* pOut, kmScalar yaw, kmScalar pitch, kmScalar roll);
///< Interpolate between 2 quaternions
kmQuaternion* kmQuaternionSlerp(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2, kmScalar t);
void kmQuaternionSlerpNum(float q1x, float q1y, float q1z, float q1w, float q2x, float q2y, float q2z, float q2w, float t, float* dstx, float* dsty, float* dstz, float* dstw);


///< Get the axis and angle of rotation from a quaternion
void kmQuaternionToAxisAngle(const kmQuaternion* pIn, struct kmVec3* pVector, kmScalar* pAngle);

///< Scale a quaternion
kmQuaternion* kmQuaternionScale(kmQuaternion* pOut, const kmQuaternion* pIn, kmScalar s);
kmQuaternion* kmQuaternionAssign(kmQuaternion* pOut, const kmQuaternion* pIn);
kmQuaternion* kmQuaternionAdd(kmQuaternion* pOut, const kmQuaternion* pQ1, const kmQuaternion* pQ2);
kmQuaternion* kmQuaternionRotationBetweenVec3(kmQuaternion* pOut, const struct kmVec3* vec1, const struct kmVec3* vec2, const struct kmVec3* fallback);
struct kmVec3* kmQuaternionMultiplyVec3(struct kmVec3* pOut, const kmQuaternion* q, const struct kmVec3* v);
//add by hgl
kmScalar kmQuatToAxisAngle(struct kmVec3* pOut, kmScalar* pAngle, const kmQuaternion* pIn );
#ifdef __cplusplus
}
#endif

#endif
