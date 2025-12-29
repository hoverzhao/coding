/**
 * Author:    Tridib Samanta
 * Created:   14.11.2019
 **/

#include<iostream>

using namespace std;
//				1: true
//				0: false
//
//				1 && 1 = 1     与&&   //肚子疼，和有纸巾，同时成立，才能使拉屎成功的事情体面的完成
//									  //两条件同时为真，结果为真
//				1 && 0 = 0
//				0 && 1 = 0
//				0 && 0 = 0
//
//
//				1 || 1 = 1 		或|| // 2人拉屎，只要有一个人拉出屎，房间就会很臭
//									  //两条件有一个为真，结果就为真
//				1 || 0 = 1
//				0 || 1 = 1
//				0 || 0 = 0
//

int main()
{
    // AND - &&
    // True only when both the expressions are true

    cout << (7>5 && 5!=10) <<endl;
		 //  1		1
			 
    cout << (2>5 && 5!=10) <<endl;
    // OR - ||
    // True when both the expressions are true or only one of them is true.
	// 		 0		 1

    cout << (2>5 || 5!=10) <<endl;
	//		  0		1
    cout << (2>5 || 5!=5) <<endl;
	//		  0		0


    // NOT - !
    // Return true if result is false and vice versa.
    cout << !(7>5 && 5!=10) <<endl;
		//    1		1

	return 0;
}
