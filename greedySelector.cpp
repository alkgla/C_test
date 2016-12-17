//̰���㷨
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
    // �����
    void greedySelector () 
    {
        __sortTime () ;
        // ��һ���һ������
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
    // ���ջ����ʱ��ǵݼ�����
    void __sortTime () 
    {
        sort (m_vTimeList.begin(), m_vTimeList.end()) ;
        for (vector<ActivityTime>::iterator ite = m_vTimeList.begin() ;ite != m_vTimeList.end() ; ++ ite) {
            cout << ite->m_nStart << ", "<< ite ->m_nEnd << endl ;
        }
    }
	
private:
    vector<ActivityTime>    m_vTimeList ;    // �ʱ�䰲���б�
    vector<bool>            m_bvSelectFlag ;// �Ƿ��Ż��־
    int    m_nCount ;    // �ܻ����
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