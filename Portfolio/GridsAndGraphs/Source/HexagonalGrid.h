#pragma once

#include <cstdint>

template<typename T>
class HexagonNode
{
	typedef HexagonNode<int32_t> Hexagon;
	typedef HexagonNode<float> FractionalHexgaon;

	HexagonNode(T inQ, T inR, T inS)
		: q(inQ)
		, r(inR)
		, s(inS)
	{

	}

	const T q;
	const T r;
	const T s;
};

template<typename T>
class HexagonalGrid
{
public:
	HexagonalGrid() = default;
	~HexagonalGrid() = default;
};