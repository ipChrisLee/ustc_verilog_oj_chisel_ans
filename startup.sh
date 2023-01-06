SBT_PROJ_NAME=Test
CMAKE_PROJ_NAME=Test
CMAKE_EXE_NAME=test
NEW_GIT=                        # create new git if you define NEW_GIT
SBT_PATH="$(which sbt)"

CMAKE_TMP=template_files/cmake.tmp
SBT_TMP=template_files/sbt.tmp

cp template_files/CMakeLists.txt.template "${CMAKE_TMP}"
cp template_files/build.sbt.template "${SBT_TMP}"

if [ -z "${SBT_PROJ_NAME}" ] || [ -z "${SBT_PATH}" ] || [ -z "${CMAKE_PROJ_NAME}" ] || [ -z "${CMAKE_EXE_NAME}" ];then
  echo "ERROR!"
  exit 1
fi

# sbt
sed -i "s|__SBT_PATH|\"""${SBT_PATH}""\"|" "${CMAKE_TMP}"
sed -i "s/__SBT_PROJ_NAME/""${SBT_PROJ_NAME}/" "${SBT_TMP}"

# nvboard
if [ -n "${NVBOARD_HOME}" ];then
  echo "NVBoard found : ""${NVBOARD_HOME}"
  sed -i "s|__NVBOARD_HOME|\"""${NVBOARD_HOME}""\"|" "${CMAKE_TMP}"
fi

# cmake
sed -i "s/__CMAKE_PROJ_NAME/""${CMAKE_PROJ_NAME}/" "${CMAKE_TMP}"
sed -i "s/__CMAKE_EXE_NAME/""${CMAKE_EXE_NAME}/" "${CMAKE_TMP}"

mv "${CMAKE_TMP}" CMakeLists.txt
mv "${SBT_TMP}" build.sbt

# git
if [ -n "${NEW_GIT}" ];then
	rm -rf .git
	git init
fi
