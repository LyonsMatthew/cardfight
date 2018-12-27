#include "Block.h"
#include "Player.h"

Block::Block(int block, Player& target)
	: block(block), target(target)
{
}

Block::~Block()
{
}

void Block::trigger()
{
	target.block_damage(Block::block);
}
