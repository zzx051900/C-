/* --------------------------------------------------------------
 * File          : qjumper.c
 * Authors       : 西安电子科技大学:网络与信息安全国家级实验教学中心
 * Created on    : <2024-02-01>
 * Last modified : <2024-03-01>
 * LICENSE       : 由实验教学中心拥有，分发需申请并征得同意
 * -------------------------------------------------------------*/

#include "common.h"

int main(int argc, char const *argv[])
{
  pid_t pid = getpid();
  struct sched_param param = {.sched_priority = OUR_PRIO};
  int retval = sched_setscheduler(pid, SCHED_RR, &param);
  if (retval == -1)
    {
      printf("Setscheduler Error! Maybe you need sudo.\n");
      return 2;
    }
  sub(5);
  return 0;
}
