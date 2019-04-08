#pragma once

class inblock_allocator_heap
{
private:
	void* heap;
	size_t size;

public:
	void operator()(void*ptr, size_t n_bytes)
	{
		this->heap = ptr;
		this->size = n_bytes;
	}
};


template<typename T, typename HeapHolder>
class inblock_allocator
{
private:
	inblock_allocator_heap heap;

public:

	using value_type = T;

	inblock_allocator()
	{
		heap = HeapHolder.heap;
	}

	template<typename T>
	inblock_allocator(const inblock_allocator<U, HeapHolder>&)
	{

	}

	~inblock_allocator()
	{
		
	}

	T* allocate(size_t n)
	{
		return (T*)malloc(n);
	}

	void deallocate(T* p, std::size_t n)
	{

	}
};
