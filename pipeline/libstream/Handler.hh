#ifndef __HANDLER_H__
#define __HANDLER_H__

class Handler {
private:
  int step;
  char name[];
  Mutex lock;

protected:
  void doProcess();
};

struct handler_node {
  Handler *handler;
  struct Handler *next;
  struct Handler *pre;
};

typedef struct handler_node* handler_node_t;

class HandlerList {
public:
  HandlerList* createNew(int nThread, int nFrames, int w, int h, uint32_t fmt, int fps);
  void add(handler_t handler);
  void del(handler_t handler);
  Handler* getNodeByStep(int step);

protected:
  HandlerList();
  virtual ~HandlerList();

private:
  handler_node_t handlers;
  handler_node_t curHandler;
  int numOfHandler;
};

#endif