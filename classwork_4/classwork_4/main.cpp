#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

template <class Iter> 
Iter myunique(Iter first, Iter last) {
	Iter readptr = first;
	++readptr;
	Iter writeptr = first;
	for (; readptr != last; ++readptr) {
		if (*readptr == *writeptr)
			++readptr;
		else {
			++writeptr;
			*writeptr = *readptr;
		}
	}
	return ++writeptr;
}

template <class Iter>
Iter myadjacent_find(Iter first, Iter last)
{
	Iter move = first;
	for (++move; move != last; ++move, ++first) {
		if (*first == *move) {
			return first;
		}
		
	}
	return last;
}


int main() {
	
	std::vector<int> v = { 1,2,3,1,2,3,3,4,5,4,5,6,7 };
	std::vector<int>::iterator ad_f= myadjacent_find(v.begin(), v.end());
	std::cout << *ad_f << std::endl;
	
	/*std::sort(v.begin(), v.end());
	std::vector<int>::iterator t = myunique(v.begin(), v.end());
	v.erase(t, v.end());

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
	}
	std::cout << std::endl;
	*///1st 

	////1
	//std::vector<int> a(8,0);
	////2
	//std::fill(a.begin() + a.size() / 2, a.end(),5);
	////3
	//std::vector<int>::iterator itTo3rd = a.begin()+2;
	////4
	//*itTo3rd += 3;
	//// 5
	//std::vector<int>::iterator min = std::find(a.begin(), a.end(), 3);
	////6:compare 5 and 3
	//bool bigger = min == itTo3rd;
	////7
	//int countNonFirst = std::count(a.begin()+1, a.end(), 0);
	////8
	//for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
	//	std::cout << *it;	
	//}
	////9
	//int max = a.begin();
	//for (std::vector<int>::iterator it = a.begin()+1; it != a.end(); ++it) {
	//	if (max < *it) {
	//		max = *it;
	//	}
	//}
	////10
	//std::vector<int>::iterator maxIter = a.begin();
	//for (std::vector<int>::iterator it = a.begin() + 1; it != a.end(); ++it) {
	//	if (max < *it) {
	//		maxIter = it;
	//	}
	//}
	
	//2nd 0 task

	//int size;
	//std::cout << "Enter size: ";
	//std::cin >> size;
	//std::list<int> l;
	//for (int i = 0; i < size; ++i) {
	//	int temp;
	//	std::cin >> temp;
	//	l.push_back(temp);
	//}
	////function
	//std::list<int>::iterator first0 = std::find(l.begin(), l.end(), 0);
	//if (first0 != l.end()) {
	//	++first0;
	//	std::list<int>::iterator second0 = std::find(first0, l.end(), 0);
	//	if (second0 != l.end()) {
	//		l.erase(second0);
	//	}
	//}
	////
	//for (std::list<int>::iterator it = l.begin(); it!=l.end(); ++it){
	//	std::cout << *it;
	//}

	//3rd
	
	//std::string st = "RRKQBBNNpppppppp";
	////std::string::iterator st;
	//std::string::iterator firstR = std::find(st.begin(), st.end(), 'R');
	//if (firstR != st.end())
	//{
	//	++firstR;
	//	std::string::iterator secondR = std::find(firstR, st.end(), 'R');
	//	if (secondR != st.end()) {
	//		std::string::iterator king = std::find(firstR, secondR, 'K');
	//		if (king != st.end()) {
	//			std::cout << "Yes" << std::endl;
	//		}
	//		std::cout  << "NO" << std::endl;
	//	}
	//}
	//

	//task 4 Adjacent_find

	/*std::list<int> l = { 1, 1, 1, 3, 2, 2, 3, 4, 5, 1 };
	while (true)
	{
		std::list<int>::iterator it = std::adjacent_find(l.begin(), l.end());
		if (it == l.end())
			break;
		l.erase(l.erase(it));
		for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) 
		{
			std::cout << *it;
		}
		std::cout << std::endl;
	}
	*/
	
	
	system("pause");
}