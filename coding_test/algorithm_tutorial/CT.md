# CT 

> Computational Thinking



## 논리와 증명

__아래의 식을 변형하여 간단하게 하시오__
$$
(p\and \sim q ) \or (p\and q)
$$
pf)
$$
p\and (\sim q \and q)\\p
$$





$$
(p \or \sim q) \and (\sim p \or \sim q)
$$
pf)
$$
(p \and \sim p) \or \sim q \\ \sim q
$$



(문제12)
자연수 $n$에 대하여, $n^2$ 이 3의 배수이면 $n$은 3의 배수임을 증명하라

pf)

자연수 $n$에 대해여서 3의 배수가 아닌 수를 나열하면 다음과 같다.
$3n+1$, $3n+2$

1)$3n+1$인 경우
$(3n+1)^2 = 9n^2 + 6n + 1$ 이므로 3의 배수가 아니다

2)$3n+2$인 경우
$(3n+2)^2 = 9n^2 + 12n + 1$ 이므로 3의 배수가 아니다

대우가 참이므로 원명제는 참이다.



## 수와 표현

(문제4)
$x=log_a yz$일 때 x를 밑이 2인 로그들로 표현하시오

$a^x = yz$
$xlog_2 a = log_2 yz$
$x = $${log_2yz}\over{log_2a}$



## 집합과 조합론

(문제16)
52개 카드에서 5개 카드 조합을 만들 때, 숫자가 같은 카드가 한 쌍도 없는 경우는 몇 가지인가
(조건이 부실해서 트럼프 카드라고 가정하고 풀이함)

숫자 카드가 1부터 k까지 있다고 할때 : 
하나를 뽑으면 그 숫자를 제외한 나머지 카드 더미에서 하나를 선택하면 된다.
52x48x44x40x36 / 5! = 1,317,888



숫자 카드가 1부터 10이라고 할 때:
총 40개의 카드
40x36x32x28x24 / 5! = 258,048

## 기초 수식
