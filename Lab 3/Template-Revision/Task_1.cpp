#include "Course.h"

int main() 
{
    OnlineCourse online(8, 3);
    OfflineCourse offline(6, 4);

    Course* course;

    course = &online;
    course->duration();

    cout << endl;

    course = &offline;
    course->duration();

    return 0;
}