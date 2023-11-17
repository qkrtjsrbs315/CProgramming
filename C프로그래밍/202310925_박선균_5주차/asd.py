import os

# 원래 파일 이름의 접두사와 접미사
prefix = "ch05_"
suffix = ".c"

# 변경될 파일 이름의 접두사와 접미사
new_prefix = "ch05_ex"
new_suffix = ".cpp"

# 파일 이름 변경
for i in range(1, 18):
    # 원래 파일 이름 생성
    original_filename = f"{prefix}{i}{suffix}"
    
    # 새로운 파일 이름 생성
    new_filename = f"{new_prefix}{i:02}{new_suffix}"
    
    # 파일 이름 변경
    os.rename(original_filename, new_filename)

print("파일 이름이 성공적으로 변경되었습니다.")
