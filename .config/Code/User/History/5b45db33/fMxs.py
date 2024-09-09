pass_fail = lambda marks : "Pass" if marks >= 50 else "Fail"

grades = [50, 80, 90, 40, 30, 70]
output = []
for grade in grades:
    output.append(pass_fail(grades))

print(output)