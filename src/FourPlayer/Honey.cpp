#include "Game/Entities/ItemHoney.h"

namespace Game
{
    


namespace ItemHoney
{

void Mgr::onCreateModel(SysShape::Model* model) {

    for (u16 j = 0; j < model->mJ3dModel->mModelData->getShapeNum(); j++) {
        J3DShape* shape = model->mJ3dModel->mModelData->mShapeTable.mItems[j];
        shape->setTexMtxLoadType(0x2000);
    }

	model->getJ3DModel()->newDifferedDisplayList(0x1000200);
	model->getJ3DModel()->calc();
	model->getJ3DModel()->calcMaterial();
	model->getJ3DModel()->makeDL();
	model->getJ3DModel()->lock();
}

} // namespace ItemHoney

} // namespace Game
