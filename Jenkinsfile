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
        stage('Checkout') {
            steps {
                checkout([$class: 'GitSCM',
                    branches: [[name: "*/${params.BRANCH_NAME}"]],
                    userRemoteConfigs: [[
                        url: 'git@github.com:YourUser/YourRepo.git',
                        credentialsId: 'your-ssh-key-id'
                    ]]
                ])
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
