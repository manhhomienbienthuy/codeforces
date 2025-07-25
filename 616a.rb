a = gets.chomp
b = gets.chomp
while a[0] == '0'
  a = a[1..-1]
end
while b[0] == '0'
  b = b[1..-1]
end
if a.length > b.length
  puts ">"
  exit
end
if a.length < b.length
  puts "<"
  exit
end

(0..a.length - 1).each do |i|
  if a[i] < b[i]
    puts "<"
    exit
  end
  if a[i] > b[i]
    puts ">"
    exit
  end
end
puts "="
