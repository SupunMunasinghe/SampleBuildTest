pipeline {
    agent any

    parameters {
        string(name: 'BRANCH_NAME', defaultValue: 'main', description: 'Branch to build')
    }
    environment {
        BUILD_DIR_DEBUG = "build"
        BUILD_DIR_RELEASE = "build-release"
    }

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