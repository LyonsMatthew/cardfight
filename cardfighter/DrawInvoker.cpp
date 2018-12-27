#include "DrawInvoker.h"
#include <iostream>

DrawInvoker::DrawInvoker()
{
}

DrawInvoker::~DrawInvoker()
{
}

std::vector<DrawInvoker*> DrawInvoker::get_invokers()
{
	return DrawInvoker::invokers;
}

void DrawInvoker::register_invoker(DrawInvoker& invoker)
{
	invokers.push_back(&invoker);
	build_draw_queue();
}

void DrawInvoker::unregister_invoker(DrawInvoker & invoker)
{
	invokers.erase(std::remove(invokers.begin(), invokers.end(), &invoker), invokers.end());
	build_draw_queue();
}

void DrawInvoker::initialize_draw_queue(DrawInvoker& invoker)
{
	draw_queue.clear();
	draw_queue.push_back(&invoker);
	build_draw_queue();
}

void DrawInvoker::build_draw_queue()
{
	if (draw_queue.empty()) return;
	DrawInvoker* first = draw_queue.front();
	draw_queue.clear();
	std::queue<DrawInvoker*> queue;
	queue.push(first);
	draw_queue.push_back(first);
	build_draw_queue_helper(*first, queue);
}

void DrawInvoker::build_draw_queue_helper(DrawInvoker& invoker, std::queue<DrawInvoker*>& queue)
{
	for(DrawInvoker* young_invoker : invoker.get_invokers())
	{
		queue.push(young_invoker);
		draw_queue.push_back(young_invoker);
	}
	queue.pop();
	if (queue.empty()) return;
	build_draw_queue_helper(*queue.front(), queue);
}

void DrawInvoker::reverse_invokers(DrawInvoker& invoker)
{
	DrawInvoker* old_front = DrawInvoker::draw_queue.front();
	DrawInvoker::initialize_draw_queue(invoker);
	for (DrawInvoker* invoker : draw_queue)
	{
		invoker->reverse();
	}
	initialize_draw_queue(*old_front);
}


std::vector<DrawInvoker*> DrawInvoker::draw_queue = std::vector<DrawInvoker*>();