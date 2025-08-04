pipeline {
    agent any

    parameters {
        string(name: 'BRANCH_NAME', defaultValue: 'main', description: 'Branch to build')
        choice(name: 'BUILD_TYPE', choices: ['Release', 'Debug'], description: 'CMake build type')
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: params.BRANCH_NAME,
                    url: 'git@github.com:SupunMunasinghe/SampleBuildTest.git'
            }
        }
        stage('Configure') {
            steps {
                sh """
                    cmake -S . -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
                """
            }
        }
        stage('Build') {
            steps {
                sh """
                    cmake --build build --config ${BUILD_TYPE}
                """
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
