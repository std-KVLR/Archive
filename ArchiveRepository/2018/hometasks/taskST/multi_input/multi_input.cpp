 group1<T4> (x.a4_); 
}



template <class T1,class T2,class T3,class T4,class T5>
inline
group4<T1,T2,T3,T4> 
group_head( group5<T1,T2,T3,T4,T5> const& x)
{
   return group4<T1,T2,T3,T4> (x.a1_,x.a2_,x.a3_,x.a4_); 
}

template <class T1,class T2,class T3,class T4,class T5>
inline
group1<T5> 
group_last( group5<T1,T2,T3,T4,T5> const& x)
{
   return group1<T5> (x.a5_); 
}



template <class T1,class T2,class T3,class T4,class T5,class T6>
inline
group5<T1,T2,T3,T4,T5> 
group_head( group6<T1,T2,T3,T4,T5,T6> const& x)
{
   return group5<T1,T2,T3,T4,T5> (x.a1_,x.a2_,x.a3_,x.a4_,x.a5_); 
}

template <class T1,class T2,class T3,class T4,class T5,class T6>
inline
group1<T6> 
group_last( group6<T1,T2,T3,T4,T5,T6> const& x)
{
   return group1<T6> (x.a6_); 
}



template <class T1,cla