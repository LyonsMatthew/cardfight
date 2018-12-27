#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <forward_list>
#include <algorithm>

class DrawInvoker : public sf::Drawable
{
public:
	DrawInvoker();
	~DrawInvoker();

	std::vector<DrawInvoker*> get_invokers();
	void register_invoker(DrawInvoker& invoker);
	void unregister_invoker(DrawInvoker& invoker);

	static void initialize_draw_queue(DrawInvoker& invoker);
	static void build_draw_queue();
	static void build_draw_queue_helper(DrawInvoker& invoker, std::queue<DrawInvoker*>& queue);
	
	static std::vector<DrawInvoker*> draw_queue;
	
	static void reverse_invokers(DrawInvoker& invoker);

	virtual void reverse() = 0;

protected:
	std::vector<DrawInvoker*> invokers;
	virtual void register_invokers() = 0;

private:

};