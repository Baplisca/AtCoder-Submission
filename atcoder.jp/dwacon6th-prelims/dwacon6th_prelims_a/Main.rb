n = gets.to_i
s = []
t = []
is_start = false
res = 0
cnt = 0
for i in 0..n-1 do
    S = gets.split(' ')
    s.append(S[0])
    s.flatten!
    t.append(S[1].to_i)
    t.flatten!
end
x = gets.chomp
while cnt < n do
    if is_start
        res += t[cnt]
    end
    if s[cnt] == x
        is_start = true
    end
    cnt = cnt + 1
end

puts res