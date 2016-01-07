#pragma once

#include "Maths\CVector.h"

struct ColDef
{
	CRect area;
	uint32_t field_10;
	uint32_t field_14;
	uint32_t field_18;
	uint32_t field_1C;
	uint16_t field_20;
	uint16_t modelIdStart;
	uint16_t modelIdEnd;
	uint16_t refCount;
	bool bActive;
	bool bCollisionIsRequired;
	bool bProcedural;
	bool bInterior;
};
class CColStore
{
public:
	/*
	* AddColSlot(char const*)
	*/ 
	static void AddCollisionNeededAtPosn(const CVector& pos);
	static void AddRef(int colNum);
	/* BoundingBoxesPostProcess()
	* EnsureCollisionIsInMemory(CVector const&)
	* FindColSlot(char const*)
	* GetBoundingBox(int)
	* HasCollisionLoaded(CVector const&, int)
	*/ 
	static void IncludeModelIndex(int colNum, int modelId);
	/* Initialise()
	* LoadAllBoundingBoxes()
	* LoadAllCollision()
	* LoadCol(int, char const*)
	* LoadCol(int, unsigned char*, int)
	* LoadCollision(CVector, bool)
	* RemoveAllCollision()
	*/ 
	static void RemoveCol(int colNum);
	/* RemoveColSlot(int)
	*/ 
	static void RemoveRef(int colNum);
	/* RequestCollision(CVector const&, int)
	*/ 
	static void SetCollisionRequired(const CVector& pos, int areaCode);
	/* Shutdown()
	*/
private:
	/* m_onlyBB
	*/ 
	static CPool<ColDef>* ms_pColPool;
	static class CQuadTreeNode* ms_pQuadTree;
};