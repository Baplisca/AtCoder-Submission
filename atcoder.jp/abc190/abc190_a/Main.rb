d = gets.split(' ').map(&:to_i)
c = d[2]
b = d[1]
a = d[0]

if c == 1
    if b <= a
        puts "Takahashi"
    else
        puts "Aoki"
    end
else
    if a <= b
        puts "Aoki"
    else
        puts "Takahashi"
    end
end