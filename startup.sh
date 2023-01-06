SBT_PROJ_NAME=Test
TESTING=y

SBT_PATH="$(which sbt)"

if [ -z "${SBT_PROJ_NAME}" ] || [ -z "${SBT_PATH}" ];then
  echo "ERROR!"
  exit 1
fi

sed "5s|.*|set(SBT_PATH \"""${SBT_PATH}""\")|" template_files/CMakeLists.txt.template > CMakeLists.txt
sed "11s|.*|\tname := \"""${SBT_PROJ_NAME}""\",|" template_files/build.sbt.template > build.sbt

if [ -z "${TESTING}" ];then
	rm -rf .git
	git init
fi
