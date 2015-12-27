
/** Enum defining
 *  Task Status
**/
enum TASKSTATUS = {
      INITIATED, 
      STARTED, 
      COMPLETED, 
      FAILED
};

/** ResourceAttribute Class
  * representing attributes of
  * resource offers
  * and resource needs.
**/
class ResourceAttribute {
   private:
      unsigned int m_resource;
   public:
     TaskAttributes();
     virtual ~TaskAttributes();
     unsigned int getResourceAttr() const;
     void setResourceAttr(unsigned int &l_resource);
};
/** Resource class
  * encapsulating a resource offer
  * or need.
**/ 
class Resource {
  private:
     vector<ResourceAttribute> m_resource;
  public:
     Resource();
     virtual ~Resource();
     void pushResurce(const ResourceAttribute &l_resource);
};

/** Task Class
  * representing task requested
  * and task in execution.
**/
class Task {
private:
  TASKSTATUS m_taskstatus;   
public:
  Task();
  virtual ~Task();
  void run();
  void getStatus();
}

/** TaskScheduler, the main 
 * scheduler which finds the best
 * match
**/
class TaskScheduler {
private:
  std::stack<Task> m_tasks;
public:
  TaskScheduler();
  virtual ~TaskScheduler();
  void pushTask(Task &l_task);
};
