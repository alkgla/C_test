//贪心算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

struct ActivityTime
{
public:
    ActivityTime (int nStart, int nEnd) 
        : m_nStart (nStart), m_nEnd (nEnd) 
    { }
    ActivityTime ()
        : m_nStart (0), m_nEnd (0)
    { }
    friend 
		bool operator < (const ActivityTime& lth, const ActivityTime& rth) 
    {
        return lth.m_nEnd < lth.m_nEnd ;
    }
public:
    int m_nStart ;
    int m_nEnd ;
} ;

class ActivityArrange 
{
public:
    ActivityArrange (const vector<ActivityTime>& vTimeList) 
    {
        m_vTimeList = vTimeList ;
        m_nCount = vTimeList.size () ;
        m_bvSelectFlag.resize (m_nCount, false) ;
    }
    // 活动安排
    void greedySelector () 
    {
        __sortTime () ;
        // 第一个活动一定入内
        m_bvSelectFlag[0] = true ;    
        int j = 0 ;
        for (int i = 1; i < m_nCount ; ++ i) {
            if (m_vTimeList[i].m_nStart > m_vTimeList[j].m_nEnd) {
                m_bvSelectFlag[i] = true ;
                j = i ;
            }
        }
        
        copy (m_bvSelectFlag.begin(), m_bvSelectFlag.end() ,ostream_iterator<bool> (cout, " "));
        cout << endl ;
    }
	
private:
    // 按照活动结束时间非递减排序
    void __sortTime () 
    {
        sort (m_vTimeList.begin(), m_vTimeList.end()) ;
        for (vector<ActivityTime>::iterator ite = m_vTimeList.begin() ;ite != m_vTimeList.end() ; ++ ite) {
            cout << ite->m_nStart << ", "<< ite ->m_nEnd << endl ;
        }
    }
	
private:
    vector<ActivityTime>    m_vTimeList ;    // 活动时间安排列表
    vector<bool>            m_bvSelectFlag ;// 是否安排活动标志
    int    m_nCount ;    // 总活动个数
} ;

int main()
{
    vector<ActivityTime> vActiTimeList ;
    vActiTimeList.push_back (ActivityTime(1, 4)) ;
    vActiTimeList.push_back (ActivityTime(3, 5)) ;
    vActiTimeList.push_back (ActivityTime(0, 6)) ;
    vActiTimeList.push_back (ActivityTime(5, 7)) ;
    vActiTimeList.push_back (ActivityTime(3, 8)) ;
    vActiTimeList.push_back (ActivityTime(5, 9)) ;
    vActiTimeList.push_back (ActivityTime(6, 10)) ;
    vActiTimeList.push_back (ActivityTime(8, 11)) ;
    vActiTimeList.push_back (ActivityTime(8, 12)) ;
    vActiTimeList.push_back (ActivityTime(2, 13)) ;
    vActiTimeList.push_back (ActivityTime(12, 14)) ;
	
    ActivityArrange aa (vActiTimeList) ;
    aa.greedySelector () ;
    return 0 ;
}