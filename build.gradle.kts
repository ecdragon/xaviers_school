import java.text.SimpleDateFormat
import java.util.Date

val versionFile = file("projectVersion.txt")

fun getCurrentVersion(): String {
    println("Reading the current version from projectVersion.txt")
    return if (versionFile.exists()) {
        versionFile.readText().trim().also {
            println("Current version read: $it")
        }
    } else {
        throw GradleException("Version file not found: projectVersion.txt")
    }
}

fun incrementPatchVersion(version: String): String {
    println("Incrementing the patch version for: $version")

    val parts = version.split(".")
    if (parts.size != 5) {
        throw GradleException("Invalid version format in projectVersion.txt: $version")
    }

    val major = parts[0]
    val minor = parts[1]
    val patch = parts[2].toInt() + 1
    val newPatch = patch.toString()

    // Create a new timestamp
    val date = Date()
    val dateFormat = SimpleDateFormat("yyyyMMdd")
    val timeFormat = SimpleDateFormat("HHmmss")
    val datePart = dateFormat.format(date)
    val timePart = timeFormat.format(date)

    val newVersion = "$major.$minor.$newPatch.$datePart.$timePart"
    println("New version generated: $newVersion")

    return newVersion
}

tasks.register("updateProjectVersion") {
    doLast {
        println("Running updateProjectVersion task")
        val currentVersion = getCurrentVersion()
        val newVersion = incrementPatchVersion(currentVersion)
        versionFile.writeText(newVersion)
        println("Updated version written to projectVersion.txt: $newVersion")
    }
}

// Set the project version from the file
version = getCurrentVersion()

allprojects {
    version = rootProject.version
    repositories {
        // Repositories for all subprojects, if needed
        mavenCentral()
    }
}

subprojects {
    apply(plugin = "base")
}
