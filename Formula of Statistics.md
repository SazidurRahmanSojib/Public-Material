# Formula Of Statistics  
## Formula:  
#### Basic: Central Tendency (Mean, Median, Mode) and Measure of Dispersion (Range, Variance, Standard deviation, Mean deviation, Quartile deviation)  

1. Mean: average value
    - For ungroup data: $\bar{x}=\frac{\sum{}^n _{i=1}x_i}{n} $  
    x<sub>i</sub>=each individual observation; n=total number of observations.
    - For group data: $\bar{x}=\frac{\sum{}^k_{i=1}f_i.m_i}{n} $  
    f<sub>i</sub>=frequency of the i<sup>th</sup> class; m<sub>i</sub>= midpoint of the i<sup>th</sup> class; k=total number of class intervals; n= total number of observations(sum of frequency).
2. Mode: most frequent value
    - For ungroup data: the value that appears most frequently. If multiple values have the same highest frequency, the dataset is considered multimodal.
    - For group data: $Mode = L +\frac{f_m-f_{m-1}}{f_m-f_{m-1}+f_m-f_{m+1}}.w $  
    L= lower limit of modal class; f<sub>m</sub>= frequency of the modal group; f<sub>m-1</sub>= frequency of the group before the modal group; f<sub>m+1</sub>= frequency of the group after the modal group; w=Width of the class interval
3. Median: middle value
    - For ungroup data: a. If the number of observations (n) is odd, the median is simply the value at position (n+1)/2.  
    b. If the number of observations (n) is even, the median is the average of the two middle values at positions n/2 and (n/2)+1.
    - For group data: $Median=L+ \frac{\frac{n}{2} - F_c}{f}.w$  
    L= Lower boundary of the median class, n= total number of observation; F<sub>c</sub>=Cumulative frequency of the class before the median class; f= Frequency of the median class; w=Width of the class interval
4. Variance:
    - For ungroup data: $\sigma{}^2=\frac{\sum{}^n_{i=1}(x_i-\bar{x})^2}{n} $  
    x<sub>i</sub>= each individual observation,  $\bar{x}{}$  = mean of the dataset, n= total number of observations.
    - For group data: $\sigma{}^2=\frac{\sum{}^k_{i=1}f_i.(m_i-\bar{x})^2}{n} $  
     f<sub>i</sub>=frequency of i<sup>th</sup> class; 
     $\bar{x}{}$  = mean of the dataset, m<sub>i</sub> = midpoint of the i<sup>th</sup> class interval; n = total number of observations (sum of frequencies), k= total number of class intervals.
5. Standard Deviation:
    - For ungroup data: $\text{Standard Deviation} (\sigma{})=\sqrt{ \text{variance }(\sigma{}^2}) $  
    - For group data:  $\text{Standard Deviation} (\sigma{})=\sqrt{ \text{variance }(\sigma{}^2}) $  
6. Mean Deviation:
    - For ungroup data: 
     $MD =\frac{\sum{}^n_{i=1}|x_i-\bar{x}|}{n} $  
    x<sub>i</sub>= each individual observation,  $\bar{x}{}$  = mean of the dataset, n= total number of observations.
    - For group data:  $\sigma{}^2=\frac{\sum{}^k_{i=1}f_i.|m_i-\bar{x}|}{n} $  
    f<sub>i</sub>=frequency of i<sup>th</sup> class; 
    $\bar{x}{}$  = mean of the dataset, m<sub>i</sub> = midpoint of the i<sup>th</sup> class interval; n = total number of observations (sum of frequencies), k= total number of class intervals.

### Probability Distribution  

#### Discrete Distribution:  
1. Binomial Distribution: n= number of trials(fixed value), p= probability of success, x= number of success, P(x)=  the probability mass function (PMF), which gives the probability of obtaining exactly x successes in n trials, q= the probability of failure in a single trial.   
$P(x)= {}^nC_x.p^x.(1-p)^{n-x}$   
$q=1-p$  
$\text{mean, }\mu=n.p$  
$\text{variance, } \sigma{}^2=n.p(1-p)$  

2. Poisson Distribution: $\lambda=$ avaerage rate of occurrence (constant over the entire interval of observation), x= number of events, P(x) is the probability of observing x events.  
$P(x)= \frac{e^{-\lambda}.\lambda^x}{x!}$     
$\text{mean, }\mu=\lambda$  
$\text{variance, } \sigma{}^2=\lambda$


#### Continuous Distribution:
1. Exponential Distribution: λ is the rate parameter, representing the average rate of occurrence of events, x is the time duration between events, f(x∣λ) is the probability density function, representing the probability of observing a value x.  
$f(x|\lambda)=\lambda . e^{-\lambda x}$  
$\text{mean, }\mu=\frac{1}{\lambda}$   
$\text{variance,}\sigma{}^2=\frac{1}{\lambda{}^2}$  
$\text{CDF: }F(x|\lambda)=1-e^{\lambda x} \text{ ; CDF:- Cummulative Distribution Function}$  

2. Uniform Distribution: a and b are the lower and upper bounds of the range, x is the value at which we want to evaluate the CDF.  

$$
\text{PDF: }f(x|a,b)=\begin{cases} 
\frac{1}{b-a} & \text{for } a \leq x \leq b \\
0 & \text{for elsewhere}
\end{cases} 
$$  

$$
\begin{aligned}
\text{CDF: }F(x|a,b)=\frac{x-a}{b-a} \\
\text{mean, }\mu =\frac{a+b}{2} \\
\text{variance, }\sigma{}^2=\frac{(b-a)^2}{12}
\end{aligned}
$$



3. Normal Distribution: x is a specific value of the random variable, μ is the mean of the distribution, σ is the standard deviation of the distribution:  

$$
\begin{aligned}
\text{PDF: }f(x|\mu , \sigma)=\frac{1}{\sqrt{2\pi \sigma{}^2}}.e^{-\frac{(x-\mu)^2}{2\sigma{}^2}} \\
\text{CDF: }F(x|\mu,\sigma)=\int^x_\infty \frac{1}{\sqrt{2\pi \sigma{}^2}}.e^{-\frac{(t-\mu)^2}{2\sigma{}^2}} dt
\end{aligned}
$$

