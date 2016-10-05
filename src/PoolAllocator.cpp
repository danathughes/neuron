#pragma once

#include <iostream>
#include <PoolAllocator.h>

void PoolAllocator::StartUp()
{
	std::cout << "Starting memory allocator and allocating a fuckton of memory.\n";
}

void PoolAllocator::ShutDown()
{
	std::cout << "Stopping allocator and freeing that fuckton of memory.\n";

}

PoolAllocator::PoolAllocator()
{

}

PoolAllocator::~PoolAllocator()
{

}