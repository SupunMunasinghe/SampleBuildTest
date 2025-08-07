pipeline {
    agent none

    parameters {
        string(name: 'BRANCH_NAME', defaultValue: 'main', description: 'Branch to build')
    }
    environment {
        BUILD_DIR_DEBUG = "build"
        BUILD_DIR_RELEASE = "build-release"
    }

    stages {
        stage('Checkout in both Linux and Windows') {
            parallel {
                stage('Checkout in Linux') {
                    agent { label 'linux' }
                    steps {
                        echo "Building branch ${params.BRANCH_NAME}"
                        git branch: "${params.BRANCH_NAME}", credentialsId: 'github-ssh-key-2', url: 'https://github.com/SupunMunasinghe/SampleBuildTest.git'
                    }
                }
                stage('Checkout in Windows') {
                    agent { label 'windows' }
                    steps {
                        echo "Building branch ${params.BRANCH_NAME}"
                        git branch: "${params.BRANCH_NAME}", credentialsId: 'github-ssh-key-2', url: 'https://github.com/SupunMunasinghe/SampleBuildTest.git'
                    }
                }
            }
        }

        stage('Parallel Builds') {
            parallel {
                stage('Build on Linux') {
                    agent { label 'linux' }
                    stages {

                    stage('Build Debug') {
                        steps {
                            echo "Building branch ${params.BRANCH_NAME}"
                            sh '''
                                mkdir -p ${BUILD_DIR_DEBUG}
                                cd ${BUILD_DIR_DEBUG}
                                cmake -DCMAKE_BUILD_TYPE=Debug ..
                                make -j$(nproc)
                            '''
                        }
                    }
        
                    stage('Build Release') {
                        steps {
                            sh '''
                                mkdir -p ${BUILD_DIR_RELEASE}
                                cd ${BUILD_DIR_RELEASE}
                                cmake -DCMAKE_BUILD_TYPE=Release ..
                                make -j$(nproc)
                            '''
                        }
                    }
                    }   
                }

                stage('Build on Windows') {
                    agent { label 'windows' }
                    steps {
                        bat '''
                        echo Building on Windows...
                        mkdir build\\windows
                        cd build\\windows
                        cmake ..\\.. -G "Visual Studio 16 2019" -A x64
                        cmake --build . --config Release
                        '''
                        }

                    }
                }
        }
        
        
        
    }
    post {
        success {
            script {
                currentBuild.result = 'SUCCESS'
            }
        }
        failure {
            script {
                currentBuild.result = 'FAILURE'
            }
        }
    }
}