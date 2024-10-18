for ($i = 6; $i -le 10; $i++) {
    $labNum = $i.ToString("00")
    $remotePath = "spraggins_0524626@class-server:~/labs/lab$labNum/*"
    $localPath = "C:\Users\Owner\Documents\Github_Repositories\CSCI-41\lab$labNum"
    
    # Ensure the local directory exists
    if (-not (Test-Path $localPath)) {
        New-Item -ItemType Directory -Path $localPath | Out-Null
    }
    
    # Use scp to copy files (not directories)
    scp $remotePath $localPath
}
