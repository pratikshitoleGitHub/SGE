message(STATUS "External project: GLM")
message(STATUS "INSTALL_DEPENDENCIES_DIR: ${INSTALL_DEPENDENCIES_DIR}")

set(GLM_PREFIX "${INSTALL_DEPENDENCIES_DIR}/glm_prefix") 
set(GLM_INSTALL_DIR "${INSTALL_DEPENDENCIES_DIR}/glm/glm") 
set(GLM_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GLM_INSTALL_DIR} -DGLM_INSTALL_ENABLE=ON -DGLM_TEST_ENABLE_CXX_14=ON) 

#-DCMAKE_INSTALL_INCLUDEDIR=${GLM_INSTALL_DIR} -DGLM_INSTALL_CONFIGDIR=${GLM_INSTALL_DIR}

ExternalProject_Add(
    GLM_EXTERNAL
    PREFIX ${GLM_PREFIX}
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
	CMAKE_ARGS ${GLM_CMAKE_ARGS}
	INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory
                    <SOURCE_DIR>/glm ${GLM_INSTALL_DIR}
					
	INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory
		<SOURCE_DIR>/glm ${GLM_INSTALL_DIR}
		
	INSTALL_DIR ${GLM_INSTALL_DIR}
	
	LOG_DOWNLOAD ON
	LOG_UPDATE ON
	LOG_CONFIGURE ON 
	LOG_BUILD ON
	LOG_INSTALL ON 
)


				
message(STATUS "GLM_PREFIX: ${GLM_PREFIX}")
message(STATUS "GLM_INSTALL_DIR: ${GLM_INSTALL_DIR}")