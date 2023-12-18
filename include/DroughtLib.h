#include "types.h"
#include "CNode.h"
#include "Game/CurrTriInfo.h"
#include "Game/MapMgr.h"

#ifndef _DROUGHTLIB_H_
#define _DROUGHTLIB_H_


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

} // namespace DroughtLib

#endif 