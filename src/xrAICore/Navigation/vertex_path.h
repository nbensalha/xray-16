////////////////////////////////////////////////////////////////////////////
//	Module 		: vertex_path.h
//	Created 	: 21.03.2002
//  Modified 	: 02.03.2004
//	Author		: Dmitriy Iassenev
//	Description : Vertex path class
////////////////////////////////////////////////////////////////////////////

#pragma once

template<bool bEuclidianHeuristics = true>
struct CVertexPath
{
#pragma pack(push,1)
	template<typename TCompoundVertex>
    struct VertexData
    {};
#pragma pack(pop)

	template<typename TCompoundVertex>
	class CDataStorage
    {
	public:
		typedef TCompoundVertex	CGraphVertex;
		typedef	typename CGraphVertex::_index_type _index_type;
	
	public:
		IC					CDataStorage		(const u32 vertex_count);
		virtual				~CDataStorage		();
		IC		void		init				();
		IC		void		assign_parent		(CGraphVertex &neighbour, CGraphVertex *parent);
		template <typename T>
		IC		void		assign_parent		(CGraphVertex &neighbour, CGraphVertex *parent, const T&);
		IC		void		update_successors	(CGraphVertex &neighbour);
		IC		void		get_node_path		(xr_vector<_index_type> &path, CGraphVertex *best);
	};
};

#include "xrAICore/Navigation/vertex_path_inline.h"