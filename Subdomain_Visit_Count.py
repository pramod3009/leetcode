class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        result = []
        d = {}
        for i in cpdomains:
            temp = list(i.split(" "))
            num = temp[0]
            domain = temp[1]
            domain = list(domain.split("."))
            domain = domain[::-1]
            d[domain[0]] = d.get(domain[0], 0) + int(num)
            if len(domain)>=2:
                key = domain[1] + "." + domain[0]  
                d[key] = d.get(key,0) + int(num)     
            if len(domain)==3:
                key = domain[2] + "." + domain[1] + "." + domain[0]
                d[key] = d.get(key,0) + int(num)
        #print(d)
        for i in list(d.keys()):
            result.append(str(d[i])+" "+i)
        return result