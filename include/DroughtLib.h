
#ifndef _DROUGHTLIB_H_
#define _DROUGHTLIB_H_

#include "types.h"
#include "CNode.h"
#include "Game/CurrTriInfo.h"
#include "Game/MapMgr.h"
#include "Viewport.h"
#include "Sys/Sphere.h"
#include "Game/CameraMgr.h"


namespace DroughtLib
{

    // wrapper class for dynamic arrays
    template<typename T>
    class FixedSizedArray
    {
        private:
        T* object;
        int size;

        public:
        inline T& operator[](int idx) {
            return object[idx];
        }

        inline operator T*() {
            return object;
        }

        inline int GetSize() {
            return size;
        }

        inline FixedSizedArray(int objSize) {
            size = objSize;
            object = new T[objSize];
        }

        inline ~FixedSizedArray() {
            delete[] object;
        }
    };

    template<int I, typename T>
    class StaticSizedArray
    {
        private:
        T object[I];


        public:
        inline StaticSizedArray() { }
        inline StaticSizedArray(T val) {
            for (int i = 0; i < I; i++) {
                object[i] = val;
            }
        }

        inline T& operator[](int idx) {
            return object[idx];
        }

        inline operator T*() {
            return object;
        }

        inline int GetSize() {
            return I;
        }

        template <typename T2>
        inline StaticSizedArray<I, T> operator+(StaticSizedArray<I, T2>& other) {
            StaticSizedArray<I, T> ourArr;
            for (int i = 0; i < I; i++) {
                ourArr[i] = other[i] + object[i];
            }
            return ourArr;
        }

        template <typename T2>
        inline StaticSizedArray<I, T> operator-(StaticSizedArray<I, T2>& other) {
            StaticSizedArray<I, T> ourArr;
            for (int i = 0; i < I; i++) {
                ourArr[i] = other[i] - object[i];
            }
            return ourArr;
        }

        template <typename T2>
        inline StaticSizedArray<I, T> operator*(StaticSizedArray<I, T2>& other) {
            StaticSizedArray<I, T> ourArr;
            for (int i = 0; i < I; i++) {
                ourArr[i] = other[i] * object[i];
            }
            return ourArr;
        }

        template <typename T2>
        inline StaticSizedArray<I, T> operator/(StaticSizedArray<I, T2>& other) {
            StaticSizedArray<I, T> ourArr;
            for (int i = 0; i < I; i++) {
                ourArr[i] = other[i] / object[i];
            }
            return ourArr;
        }

        inline int MaxIdx() {
            T max = object[0];
            int idx = 0;

            for (int i = 1; i < I; i++) {
                if (object[i] > max) {
                    idx = i;
                    max = object[i];
                }
            }
            return idx;
        }

        inline int MinIdx() {
            T min = object[0];
            int idx = 0;

            for (int i = 1; i < I; i++) {
                if (object[i] < min) {
                    idx = i;
                    min = object[i];
                }
            }
            return idx;
        }
    };

    namespace ArrayFunctions
    {
        // Returns the index of the maximum value of the array
        template <typename T>
        inline int ArrayMax(T* array, int size) {
            T max = array[0];
            int idx = 0;

            for (int i = 1; i < size; i++) {
                if (array[i] > max) {
                    idx = i;
                    max = array[i];
                }
            }
            return idx;
        }

        // Returns the index of the maximum value of the array
        template <typename T, int A, int B>
        inline Vector2i MatrixMax(T array[A][B]) {
            T max = array[0][0];
            Vector2i vec(0, 0);

            for (int x = 0; x < A; x++) {
                for (int y = 0; y < B; y++) {
                    if (array[x][y] > max) {
                        vec.x = x;
                        vec.y = y;
                        max = array[x][y];
                    }
                }
            }
            return vec;
        }

        // Returns the index of the maximum value of the array
        template <typename T, int A, int B>
        inline Vector2i MatrixMin(T array[A][B]) {
            T min = array[0][0];
            Vector2i vec(0, 0);

            for (int x = 0; x < A; x++) {
                for (int y = 0; y < B; y++) {
                    if (array[x][y] < min) {
                        vec.x = x;
                        vec.y = y;
                        min = array[x][y];
                    }
                }
            }
            return vec;
        }

        

        // returns an array of indexes such that the indexes would assemble an array that's in accending order
        // this function has not been optimized
        template <int size, typename T>
        inline StaticSizedArray<size, int> MakeSortedIndexList(T* array) {

            StaticSizedArray<size, int> returnArray;

            for (int i = 0; i < size; i++) {
                returnArray[i] = -1;
            }

            for (int nextValue = 0; nextValue < size; nextValue++) {

                T min = array[0];
                int idx = 0;

                for (int firstIdx = 0; firstIdx < size; firstIdx++) {
                    
                    bool valueWorks = true;

                    for (int checkValue = 0; checkValue < nextValue; checkValue++) {
                        if (returnArray[checkValue] == firstIdx) {
                            valueWorks = false;
                            break;
                        }
                    }

                    if (valueWorks) {
                        min = array[firstIdx];
                        idx = firstIdx;
                    }
                }

                for (int i = 0; i < size; i++) {

                    bool valueWorks = true;

                    for (int checkValue = 0; checkValue < nextValue; checkValue++) {
                        if (returnArray[checkValue] == i) {
                            valueWorks = false;
                            break;
                        }
                    }

                    if (valueWorks && array[i] < min) {
                        idx = i;
                        min = array[i];
                    }
                }

                returnArray[nextValue] = idx; 

            }


            return returnArray;
        }

        // Returns the index of the minimum value of the array
        template <typename T>
        inline int ArrayMin(T* array, int size) {
            T min = array[0];
            int idx = 0;

            for (int i = 1; i < size; i++) {
                if (array[i] < min) {
                    idx = i;
                    min = array[i];
                }
            }
            return idx;
        }

        // Returns the sum of the array
        template <typename T>
        inline T ArraySum(T* array, int size) {
            T sum = 0;

            for (int i = 0; i < size; i++) {
                sum += array[i];
            }


            return sum;
        }

        // Returns the average of the array
        template <typename T>
        inline T ArrayAvg(T* array, int size) {
            return ArraySum(array, size) / size;
        }

    } // namespace Array

    
    inline void RotateXZ(Vector3f& vec, f32 theta) {
        vec.x = vec.x * pikmin2_cosf(theta) - vec.z * pikmin2_sinf(theta);
        vec.z = vec.z * pikmin2_sinf(theta) + vec.x * pikmin2_sinf(theta);
    }
    
    inline bool hasValidFloor(Vector3f& vec) {
        Game::CurrTriInfo triSpawn;
        triSpawn.mTriangle = nullptr;
        triSpawn.mMaxY = FLOAT_DIST_MAX;
        triSpawn.mMinY = FLOAT_DIST_MIN;
        triSpawn.mTable = nullptr;
        triSpawn.mNormalVec = Vector3f(0.0f, 1.0f, 0.0f);
        triSpawn._0D = 0;
        triSpawn.mPosition = vec;
        triSpawn._0C = 0;
        Game::mapMgr->getCurrTri(triSpawn);
        return triSpawn.mTriangle;
    }

    // don't use this
    inline Vector3f WorldToScreen(const Vector3f& point, Viewport* vp, const Matrixf& viewMatrix) {

        Vector3f usePoint = point;

        Camera* cam = vp->mCamera;
        Mtx44& projMtx = sys->mGfx->mPerspGraph.mMtx44;


        Vector3f camPos = cam->getPosition();

        f32 projection[GX_PROJECTION_SZ] = {
            0x00000000,
            projMtx[0][0],
            projMtx[0][2],
            projMtx[1][1],
            projMtx[1][2],
            projMtx[2][2],
            projMtx[2][3]
        };


        f32 viewport[GX_VIEWPORT_SZ] = {
            vp->mRect2.p1.x,
            vp->mRect2.p1.y,
            vp->mRect2.getWidth(),
            vp->mRect2.getHeight(),
            0.0f,
            1.0f
        };

        Vector3f screenPos;

        GXProject(point.x, point.y, point.z, const_cast<Matrixf&>(viewMatrix).mMatrix.mtxView, projection, viewport, &screenPos.x, &screenPos.y, &screenPos.z);
        return screenPos;
    }

    inline bool wholeSphereVisable(const Sys::Sphere& p, const CullPlane* cullplane) {
        for (int i = 0; i < 6; i++) {
            const Plane& plane = cullplane->mObjects[i];
            if (plane.calcDist(p.mPosition) <= p.mRadius) {
                return false;
            }
        }
        return true;
    }

    inline Vector3f ForceIntoCullPlanes(const Sys::Sphere& p, const CullPlane* cullplane, bool& hitBackplane) {
        hitBackplane = false;
        Vector3f point = p.mPosition;
        const f32 radius = p.mRadius;
        
        for (int i = 0; i < 6; i++) {
            
            // check if we are in this plane's bounds
            const Plane& plane = cullplane->mObjects[i];
            // note: positive radius because we want the whole sphere to be visable
            if (plane.calcDist(point) > radius) {
                
                // if we are in the bounds of this plane, we don't need to do anything
                continue;
            }
            
            if (i == 1) {
                hitBackplane = true;
                continue;
            }
            
            // if we are outside the bounds, force the point onto the plane

            Vector3f planeVector = Vector3f(plane.a, plane.b, plane.c);

            f32 sqrMagnitude = planeVector.sqrMagnitude();
            f32 magnitude = sqrtf(sqrMagnitude);
        
            /* 
             p is the point,
             v is the planeVector,
             r is the radius,
             d is the plane's d component (offset)
             a is the clostest point on the plane
             f is the resulting vector,

             (* is the dot product)
             (|x| is the magnitude of x)
             (^x is the normalized x)
            
             we want a to be on the plane, thus
             a * v = d

             we can get a by itself through the definition of a vector inverse,
             (v^-1 = v / |v|^2, thus)

             a = d(v / |v|^2)

             Consider that the normal vector is the direction 
             in which the clostest point on the plane lies, thus
             a = nv + p

             we can set the 'a's equal to eachothers getting us

             n v + p = d(v / |v|^2)

             we want to find n to get us our scalar to find a

             n v = d(v / |v|^2) - p
             n = (d(v / |v|^2) - p) * (v / |v|^2)
             
             now that we have n (albiet in quite a mess), 
             we can get the point on the plane using a = nv + p

             a = ((d(v / |v|^2) - p) * (v / |v|^2))v + p

             yikes, thats quite a mess, we can clean it up a little however

             a = (dv - (p * v)) / |v|^2 + p
             a = v(d - p * v) / |v|^2 + p

             now that we have the point on the graph, 
             we can now move it using the normal of the plane
             by the radius

             f = a + r(^v)

             (recal ^x = x / |x|)

             f = a + rv / |v|

             f = -v(d + p * v) / |v|^2 + p + rv / |v|

             combine everything for performance

             f = p - v(d + p * v - |v|r) / |v|^2

            */ 
            
            point += planeVector * ((plane.d - dot(point, planeVector) + magnitude * radius) / sqrMagnitude);
        }
        
        return point;
    }

    inline f32 getSign(f32& obj) {
        u32 one = 0x3f800000 | (0x80000000 & *(u32*)&obj);
        return *(f32*)&one;
    }

} // namespace DroughtLib

#endif 