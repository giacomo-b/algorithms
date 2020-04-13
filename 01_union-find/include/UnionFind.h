#pragma once

/*-------------------------------------------------------
Abstract class for Union-Find algorithms.

Every Union-Find implementation needs to have:

bool connected(uint p, uint q)
void join(uint p, uint q)
---------------------------------------------------------*/

#include <vector>

typedef unsigned int uint;

class UnionFind
{
public:
	explicit UnionFind(uint n)
	{
		id.reserve(n);

		for (uint i = 0; i < n; i++)
			id.push_back(i);
	}

	virtual bool connected(uint p, uint q) const = 0;

	virtual void join(uint p, uint q) = 0;

protected:
	std::vector<uint> id;
};


/*-------------------------------------------------------
Quick Find algorithm.

- Initialization cost		~ N
- Connection (join) cost	~ N
- Find (connected) cost		~ 1

Worst-case time	~ M * N
M: union-find operations
N: number of objects
---------------------------------------------------------*/

class QuickFind : public UnionFind
{
public:
	using UnionFind::UnionFind;

	bool connected(uint p, uint q) const
	{
		return id[p] == id[q];
	}

	void join(uint p, uint q)
	{
		uint p_id = id[p];
		uint q_id = id[q];

		for (uint i = 0; i < id.size(); i++)
			if (id[i] == p_id)
				id[i] = q_id;
	}
};


/*-------------------------------------------------------
Quick Union algorithm.

- Initialization cost		~ N
- Connection (join) cost	~ N (trees can get tall)
- Find (connected) cost		~ N

Worst-case time	~ M * N
M: union-find operations
N: number of objects
---------------------------------------------------------*/

class QuickUnion : public UnionFind
{
public:
	using UnionFind::UnionFind;

	bool connected(uint p, uint q) const
	{
		return root(p) == root(q);
	}

	void join(uint p, uint q)
	{
		uint i = root(p);
		uint j = root(q);
		id[i] = j;
	}

protected:
	uint root(uint i) const
	{
		while (i != id[i])
			i = id[i];

		return i;
	}
};


/*-------------------------------------------------------
Weighted Quick Union algorithm.

- Initialization cost		~ N
- Connection (join) cost	~ lg(N)
- Find (connected) cost		~ lg(N)

Worst-case time	~ N + M logN
M: union-find operations
N: number of objects
---------------------------------------------------------*/

class WeightedQuickUnion : public QuickUnion
{
public:
	WeightedQuickUnion(uint n) : QuickUnion(n)
	{
		size.assign(n, 1);
	}

	void join(uint p, uint q)
	{
		uint i = root(p);
		uint j = root(q);

		if (i == j) return;

		if (size[i] < size[j]) {
			id[i] = j;
			size[j] += size[i];
		}
		else {
			id[j] = i;
			size[i] += size[j];
		}
	}

protected:
	std::vector<uint> size;
};


/*-------------------------------------------------------
Weighted Quick Union w/ Path Compression algorithm.

- Initialization cost		~ N
- Connection (join) cost	~ lg(N)
- Find (connected) cost		~ lg(N)

Worst-case time	~ (M + N) * lg(N)
M: union-find operations
N: number of objects

- Even though theoretically non-linear in time,
  it is linear in practice
---------------------------------------------------------*/

class PathCompressionWeightedQuickUnion : public WeightedQuickUnion
{
public:
	using WeightedQuickUnion::WeightedQuickUnion;

private:
	uint root(uint i)
	{
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}

		return i;
	}

	std::vector<uint> size;
};